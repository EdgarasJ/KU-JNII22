/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1: 2023-02-09
Revision date 2: 2023-02-10
*/


#include "Kugis.h"

//constructors and destructor
Kugis::Kugis(double _topRadius, double _bottomRadius, double _altitude) {
	topCircle.setRadius(_topRadius);
	bottomCircle.setRadius(_bottomRadius);
	altitude = _altitude;
}
Kugis::Kugis(Skritulys _topCircle, Skritulys _bottomCircle, double _altitude) {
	topCircle.setRadius(_topCircle.getRadius());
	bottomCircle.setRadius(_bottomCircle.getRadius());
	altitude = _altitude;
}
Kugis::Kugis(double _topRadius, double _bottomRadius, Atkarpa _alt) {
	topCircle.setRadius(_topRadius);
	bottomCircle.setRadius(_bottomRadius);
	altitude = _alt.getLength();
}
Kugis::Kugis(double _topRadius, double _bottomRadius, Taskas _startPoint, Taskas _endPoint) {
	Atkarpa _alt(_startPoint, _endPoint);
	topCircle.setRadius(_topRadius);
	bottomCircle.setRadius(_bottomRadius);
	altitude = _alt.getLength();
}
Kugis::Kugis(double _topRadius, double _bottomRadius, double _startX, double _startY, double _endX, double _endY) {
	Atkarpa _alt(_startX, _startY, _endX, _endY);
	topCircle.setRadius(_topRadius);
	bottomCircle.setRadius(_bottomRadius);
	altitude = _alt.getLength();
}
Kugis::Kugis(Skritulys _topCircle, Skritulys _bottomCircle, Atkarpa _alt) {
	topCircle.setRadius(_topCircle.getRadius());
	bottomCircle.setRadius(_bottomCircle.getRadius());
	altitude = _alt.getLength();
}
Kugis::Kugis(Skritulys _topCircle, Skritulys _bottomCircle, Taskas _startPoint, Taskas _endPoint) {
	Atkarpa _alt(_startPoint, _endPoint);
	topCircle.setRadius(_topCircle.getRadius());
	bottomCircle.setRadius(_bottomCircle.getRadius());
	altitude = _alt.getLength();
}
Kugis::Kugis(Skritulys _topCircle, Skritulys _bottomCircle, double _startX, double _startY, double _endX, double _endY) {
	Atkarpa _alt(_startX, _startY, _endX, _endY);
	topCircle.setRadius(_topCircle.getRadius());
	bottomCircle.setRadius(_bottomCircle.getRadius());
	altitude = _alt.getLength();
}
Kugis::Kugis::~Kugis(){}
// setters
void Kugis::setAltitude(double _altitude) {
	altitude = _altitude;
}
void Kugis::setTopCircle(Skritulys _circle) {
	topCircle.setRadius(_circle.getRadius());
}
void Kugis::setTopCircleRadius(double _radius) {
	topCircle.setRadius(_radius);
}
void Kugis::setBottomCircle(Skritulys _circle) {
	bottomCircle.setRadius(_circle.getRadius());
}
void Kugis::setBottomCircleRadius(double _radius) {
	bottomCircle.setRadius(_radius);
}
void Kugis::setCircles(Skritulys _topCircle, Skritulys _bottomCircle) {
	topCircle.setRadius(_topCircle.getRadius());
	bottomCircle.setRadius(_bottomCircle.getRadius());
}
void Kugis::setCirclesRadius(double _topRadius, double _bottomRadius) {
	topCircle.setRadius(_topRadius);
	bottomCircle.setRadius(_bottomRadius);
}
// getters
double Kugis::getAltitude() {
	return altitude;
}
Skritulys Kugis::getTopCircle() {
	return topCircle;
}
Skritulys Kugis::getBottomCircle() {
	return bottomCircle;
}
double Kugis::getVolume() {
	return ((bottomCircle.getArea() + std::sqrt(bottomCircle.getArea() * topCircle.getArea()) + topCircle.getArea()) / 3.0) * altitude;
}
// print info
void Kugis::printInfoAltitude() {
	std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl << std::setw(0) << std::setfill(' ');
	std::cout << "Cone information:" << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Top circle radius" << std::setw(0) << ": " << topCircle.getRadius() << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Top circle area" << std::setw(0) << ": " << topCircle.getArea() << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Bottom circle radius" << std::setw(0) << ": " << bottomCircle.getRadius() << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Bottom circle area" << std::setw(0) << ": " << bottomCircle.getArea() << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Altitude" << std::setw(0) << ": " << altitude << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Volume" << std::setw(0) << ": " << getVolume() << std::endl;
	std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl << std::setw(0) << std::setfill(' ');
}