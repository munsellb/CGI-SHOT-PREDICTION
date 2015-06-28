
#include <opencv2/opencv.hpp>

#ifndef PREDICTIONMODEL_H
#define PREDICTIONMODEL_H

#define DEBUG 0
#define ERROR -1;
#define OK 0

class PredictionModel {
	
	public:	
		PredictionModel();
		~PredictionModel();
		
		void setFeatureMatrix( cv::Mat* matrix );
		void calculate();

		void displayFeatureMatrix();
		int writeFeatureMatrix( std::string file_path );

	private:

		cv::Mat feature_matrix;
		
};

#endif
