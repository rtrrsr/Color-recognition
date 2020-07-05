
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int minh, maxh, mins, maxs, minv, maxv;
void helptext()
{
	cout << "B������ɫ\n";
	cout << "H������ɫ\n";
	cout << "W������ɫ\n";
	cout << "R������ɫ\n";
	cout << "O������ɫ\n";
	cout << "Y������ɫ\n";
	cout << "G������ɫ\n";
	cout << "L������ɫ\n";
	cout << "P������ɫ\n";
	cout << "����Ҫ��ʶ�����ɫ��Ӧ����ĸ:";
}

//������ɫHSV��ֵ�趨
void deal(char color)
{
	switch (color) {
	case 'B':
		minh = 0;
		maxh = 180;
		mins = 0;
		maxs = 255;
		minv = 0;
		maxv = 46;
		break;
	case 'H':
		minh = 0;
		maxh = 180;
		mins = 0;
		maxs = 43;
		minv = 46;
		maxv = 220;
		break;
	case 'W':
		minh = 0;
		maxh = 180;
		mins = 0;
		maxs = 30;
		minv = 221;
		maxv = 255;
		break;
	case 'R':
		minh = 0;
		maxh = 10;
		mins = 43;
		maxs = 255;
		minv = 46;
		maxv = 255;
		break;
	case 'O':
		minh = 11;
		maxh = 25;
		mins = 43;
		maxs = 255;
		minv = 46;
		maxv = 255;
		break;
	case 'Y':
		minh = 26;
		maxh = 34;
		mins = 43;
		maxs = 255;
		minv = 46;
		maxv = 255;
		break;
	case 'G':
		minh = 35;
		maxh = 77;
		mins = 43;
		maxs = 255;
		minv = 46;
		maxv = 255;
		break;
	case 'L':
		minh = 100;
		maxh = 124;
		mins = 43;
		maxs = 255;
		minv = 46;
		maxv = 255;
		break;
	case 'P':
		minh = 125;
		maxh = 155;
		mins = 43;
		maxs = 255;
		minv = 46;
		maxv = 255;
		break;
	default:
		cout << "�������" << endl;
		exit(0);
	}
}

int main()
{
	VideoCapture cap(1); //��������ͷ��0Ϊ���������ͷ��1Ϊ���USB����ͷ

	Mat special;

	helptext();

	char color;
	cin >> color;
	deal(color);


	while (true) {

		Mat frame;              //�洢ÿһ֡��ͼ��

		cap >> frame;        //��ȡ��ǰ֡

		Mat fhsv;

		cvtColor(frame, fhsv, COLOR_BGR2HSV);   //��ͼ��ת��ΪHSVģ��

		inRange(fhsv, Scalar(minh, mins, minv), Scalar(maxh, maxs, maxv), special);          //��Ѱ��Ҫ�������ڵ���ɫ

		imshow("[pic]", special);

		imshow("Original", frame); //show the original image    

		if (waitKey(30) >= 0)
			break;
	}

	return 0;
}
