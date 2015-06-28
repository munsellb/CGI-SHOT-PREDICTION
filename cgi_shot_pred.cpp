#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "argio.hh"
#include "PredictionModel.h"

int main(int argc, const char** argv ) {

	char* input;
	char* output;

	if ( argc != 5 ) {

		std::cout<<""<<std::endl;
		std::cout<<""<<std::endl;
		std::cout<<argv[0]<<" requires 2 arguments!"<<std::endl;
		std::cout<<""<<std::endl;
		std::cout<<"-------------------------------------------"<<std::endl;
		std::cout<<"Usage: " <<argv[0]<<" -input -output "<<std::endl;
		std::cout<<"-------------------------------------------"<<std::endl;
		std::cout<<"args:  -input	  <path to feature matrix ASCII txt file>"<<std::endl;
		std::cout<<"       -output	  <path to output result .dat file>"<<std::endl;
		std::cout<<""<<std::endl;
		std::cout<<"ex:  "<<argv[0]<<" -input matrix.txt -output results.dat"<<std::endl;
		std::cout<<""<<std::endl;
		std::cout<<""<<std::endl;
		return -1;

	} 

    input = ipGetStringArgument(argv, "-input", NULL);
	output = ipGetStringArgument(argv, "-output", NULL);

	std::cout << "input " << input << " output = " << output << std::endl;

	cv::FileStorage fs( input, cv::FileStorage::READ );
	cv::Mat M;
	fs["mtx"] >> M;

	PredictionModel* model = new PredictionModel();

	model->setFeatureMatrix( &M );
	model->displayFeatureMatrix();

	delete( model );

    return 0;

}