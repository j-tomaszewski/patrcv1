#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
	Mat image = imread("in.png");

	if (!image.data)
	{
		cout << "No image data !" << endl;
		return -1;
	}

	Mat gray;
	cvtColor(image, gray, COLOR_BRG2GRAY);
	imwrite("grayscale.png", gray);

	Mat gauss;
	GaussianBlur(image, gauss, Size(3, 3), 0 , 0);
	imwrite("gauss.png", gauss);

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y; 

	Sobel(gray, grad_x, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	
	Sobel(gray, grad_y, CV16S, 0, 1, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);

	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

	imwrite("sobel.png", grad);

	
	return 0;

}
