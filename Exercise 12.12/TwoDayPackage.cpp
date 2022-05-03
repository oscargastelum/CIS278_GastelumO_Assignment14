/*************************************************************************
*
* Program : Class/ TwoDayPackage
*
* Created : 05/02/2022
*
* Programmer : Oscar Gastelum
*
*
* ************************************************************************
*  Program description/ purpose : Child class of parent class Package.
* Apart from providing parent class attributes and public methods, also
* provides:
* flat fee : double attribute
* and overloaded calculateCost() method
*
*-------------------------- Change History -------------------------------
* Programmer :
* Date :
* Description of change :
*
*************************************************************************/


//Include:
#include "Package.h" // include Package.h header file 
#include "TwoDayPackage.h" //include TwoDayPackage.h header file 



using namespace std;// eliminates the need to repeat the std:: prefix
#include <iostream> // This class inherits all members from its two parent classes istream and ostream, 			        
#include <string> // to use the string data type
#include <iomanip>
#include <sstream>

//----------------------------------------------------------------------------------------------------


//default constructor 
TwoDayPackage::TwoDayPackage() {
	setFeeAmount(flatFee);
	//Package(); // package defualt constructor 

}

//constructor 
TwoDayPackage::TwoDayPackage(const std::string& senderName,
	const std::string& senderAddress,
	const std::string& senderCity,
	const std::string& senderState,
	const std::string& senderZipCode,

	const std::string& recipientName,
	const std::string& recipientAddress,
	const std::string& recipientCity,
	const std::string& recipientState,
	const std::string& recipientZipCode,

	double weightOz,
	double costPerOunce,

	double flatFee) :
	Package(senderName, senderAddress, senderCity, senderState, senderZipCode,
		recipientName, recipientAddress, recipientCity, recipientState, recipientZipCode,
		weightOz, costPerOunce) {
	setFeeAmount(flatFee);

}




//destructor
TwoDayPackage::~TwoDayPackage() {}

//setters and getters 
void TwoDayPackage::setFeeAmount(double flatFee) {

	//throw exceptionn if not correct size 
	if (flatFee < 0) {
		throw invalid_argument{ "ERROR: Flat fee charge amount must be greater than $0" };
	}

	this->flatFee = flatFee;

}
double TwoDayPackage::getFeeAmount() const {
	return this->flatFee;
}


//calculate cost for twodayPackage; overloaded method
double TwoDayPackage::calculateCost() {
	return ((getWeight() * getCost()) + getFeeAmount());
}

std::string TwoDayPackage::getPackageType() const {
	return this->packageType;
}


//overide toString() method in order to display appropiate package infomrmation 
std::string TwoDayPackage::toString() const {

	ostringstream output;
	output << fixed << setprecision(2);
	output << Package::toString();
	output << setw(3) << "" << "2-Day Flat Fee " << getFeeAmount() << endl;

	return output.str();
}