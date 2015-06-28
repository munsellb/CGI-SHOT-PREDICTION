cmake_minimum_required(VERSION 2.8)

project( CGI_SHOT_PREDICTION )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( CGI_SHOT_PREDICTION cgi_shot_pred.cpp PredictionModel.cpp )

target_link_libraries( CGI_SHOT_PREDICTION ${OpenCV_LIBS} )
