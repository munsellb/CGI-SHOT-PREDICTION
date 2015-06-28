#include "PredictionModel.h"



//**********************************
//	Constructor
//
//
//**********************************

PredictionModel::PredictionModel() {


} // end constructor


//**********************************
//	Destructor
//
//
//**********************************

PredictionModel::~PredictionModel() {

	feature_matrix.release();

} // end destructor

// ----------------------------------------------
// METHOD: PredictionModel::calculate()
// CREATED:  06-28-2015
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void PredictionModel::calculate() {
	


} //End of calculate() method


// ----------------------------------------------
// METHOD: PredictionModel::setFeatureMatrix( cv::Mat* matrix)
// CREATED:  06-28-2015
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void PredictionModel::setFeatureMatrix( cv::Mat* matrix ) {
	
	feature_matrix = (*matrix).clone();

} //End of setFeatureMatrix() method


// ----------------------------------------------
// METHOD: PredictionModel::displayFeatureMatrix()
// CREATED:  06-28-2015
// DESCRIPTION: 
//
//.
//
//
// TODO:
//

void PredictionModel::displayFeatureMatrix() {
	
	if ( !feature_matrix.empty() ) {

		cv::Size mat_size = feature_matrix.size();

		for ( int i=0; i<mat_size.height; i++ ) {

			cv::Mat row = feature_matrix.row(i);

			for ( int j=0; j<row.cols; j++ ) {

				std::cout<<row.at<float>(j)<< " ";

			}

			std::cout<<std::endl;

		}
	}


} //End of displayFeatureMatrix() method



// ----------------------------------------------
// METHOD: int PredictionModel::writeFeatureMatrix( string file_path )
// CREATED:  06-28-2015
// DESCRIPTION: 
//
//
//
//
// TODO:
//

int PredictionModel::writeFeatureMatrix( std::string file_path ) {

	if ( feature_matrix.empty() ) {

		std::cerr<<"Feature matrix is empty"<<std::endl;
		return ERROR;

	}

	try {

		cv::FileStorage fs( file_path, cv::FileStorage::WRITE);
		fs << "mtx" << feature_matrix;

	} catch ( std::exception &error ) {

		std::cerr<<error.what()<<std::endl;

		return ERROR;

	}

	return OK;


} //End of writeFeatureMatrix() method

