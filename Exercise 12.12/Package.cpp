/*************************************************************************
*
* Program : Class/ Package
*
* Created : 05/02/2022
*
* Programmer : Oscar Gastelum
*
*
* ************************************************************************
*  Program description/ purpose : Package class provides common carrier
* package attributes including :

 sender and reciever name
 sender and reciever address
 sender and reciever city
 sender and reciever state
 sender and reciever zipCode

 Packate weight in oz
 Cost per ounce

 calculateCost() to ship the package

*
*-------------------------- Change History -------------------------------
* Programmer :
* Date :
* Description of change :
*
*************************************************************************/


//Include:
#include "Package.h" // include Package.h header file 
//#include "TwoDayPackage.h" //include TwoDayPackage.h header file 
//#include "OvernightPackage.h"


using namespace std;// eliminates the need to repeat the std:: prefix
#include <iostream> // This class inherits all members from its two parent classes istream and ostream, 			        
#include <string> // to use the string data type
#include <iomanip>
#include <sstream>

//CONSTANTS 
const unsigned int INDENT_WIDTH{ 3 };

//----------------------------------------------------------------------------------------------------




//default constructor 
Package::Package() {

	//validate user input 
	setSenderZipCode(senderZipCode);
	setRecipientZipCode(recipientZipCode);

	setWeight(weightOz);
	setCost(costPerOunce);

}








//constructor 
Package::Package(const std::string& senderName,
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
	double costPerOunce) {

	//set values using setters
	setSenderName(senderName);
	setSenderAddress(senderAddress);
	setSenderCity(senderCity);
	setSenderState(senderState);
	setSenderZipCode(senderZipCode);

	setRecipientName(recipientName);
	setRecipientAddress(recipientAddress);
	setRecipientCity(recipientCity);
	setRecipientState(recipientState);
	setRecipientZipCode(recipientZipCode);

	setWeight(weightOz);
	setCost(costPerOunce);

}




/// <summary>
/// Will validate to make sure proper zip code sintax is enterred. Either as: 
/// - 12345 or 
/// - 12345-1234
/// 
/// </summary>
/// <param name="zipCode"></param> string : valid zipcode string value
std::string Package::setValidZipCode(const std::string& zipCode) const {

	//if out of bounds
	if ((zipCode.size() < 5) || (zipCode.size() > 10)) {
		throw invalid_argument{ "ERROR: Zip code must be 5 or 9 digits long not including hyphen." };

	}
	//else if not equal to 5 or 10 in length 
	else if ((zipCode.size() > 5) && (zipCode.size() != 10) || ((zipCode.size() < 10) && (zipCode.size() != 5))) {
		throw invalid_argument{ "ERROR: Zip code must be 5 or 9 digits long not including hyphen." };

	}

	//iterrate through zipcode 
	for (size_t i{ 0 }; i < zipCode.size(); ++i) {

		//if not equal to 5th index and its not a digit		
		if (!(std::isdigit(zipCode[i])) && (i != 5)) {
			throw invalid_argument{ "ERROR: Invalid ZipCode format. Must be valid int values. Valid Input (Ex. 85711 or 85711-1234)." };

		}

		//if equal to 5th index and is a digit
		if ((std::isdigit(zipCode[i])) && (i == 5) && (zipCode.size() > 5)) {
			throw invalid_argument{ "ERROR: Invalid ZipCode format. Valid Input (Ex. 85711 or 85711-1234)." };

		}

	}

	return zipCode;

}




//setters and getters 
void Package::setWeight(const double weightOz) {

	//throw exceptionn if not correct size 
	if (weightOz < 0) {
		throw invalid_argument{ "ERROR: Weight must be greater than 0" };
	}

	this->weightOz = weightOz;

}
double Package::getWeight() const {
	return weightOz;
}



void Package::setCost(const double costPerOunce) {

	//throw exceptionn if not correct size 
	if (costPerOunce < 0) {
		throw invalid_argument{ "ERROR: Cost must be greater than 0" };
	}

	(*this).costPerOunce = costPerOunce;

}
double Package::getCost() const {
	return costPerOunce;
}



void Package::setSenderZipCode(const std::string& senderZipCode) {

	(*this).senderZipCode = setValidZipCode(senderZipCode);

}
std::string Package::getSenderZipCode() const {
	return senderZipCode;
}



void Package::setRecipientZipCode(const std::string& recipientZipCode) {
	this->recipientZipCode = setValidZipCode(recipientZipCode);

}
std::string Package::getRecipientZipCode() const{
	return recipientZipCode;
}



void Package::setSenderName(const std::string& senderName) {
	this->senderName = senderName;
}
std::string Package::getSenderName() const{
	return senderName;
}



void Package::setSenderAddress(const std::string& senderAddress) {
	this->senderAddress = senderAddress;
}
std::string Package::getSenderAddress() const{
	return senderAddress;
}



void Package::setSenderCity(const std::string& senderCity) {
	this->senderCity = senderCity;
}
std::string Package::getSenderCity() const{
	return senderCity;
}



void Package::setSenderState(const std::string& senderState) {
	this->senderState = senderState;
}
std::string Package::getSenderState() const{
	return senderState;
}



void Package::setRecipientName(const std::string& recipientName) {
	this->recipientName = recipientName;
}
std::string Package::getRecipientName() const{
	return this->recipientName;
}



void Package::setRecipientAddress(const std::string& recipientAddress) {
	this->recipientAddress = recipientAddress;
}
std::string Package::getRecipientAddress() const{
	return recipientAddress;
}



void Package::setRecipientCity(const std::string& recipientCity) {
	this->recipientCity = recipientCity;
}
std::string Package::getRecipientCity() const{
	return recipientCity;
}



void Package::setRecipientState(const std::string& recipientState) {
	this->recipientState = recipientState;
}
std::string Package::getRecipientState() const{
	return recipientState;
}





//caluclate and return cost for shipping package
double Package::calculateCost() const {
	return (getCost() * getWeight());
}


std::string Package::getPackageType() const{
	return this->packageType;
}


//return object and its elements as a string representation
std::string Package::toString() const {
	ostringstream output;
	output << fixed << setprecision(2);

	output << "\n-----------------------------" << endl;
	output << setw(INDENT_WIDTH) << "" << getPackageType() << endl;
	output << "-----------------------------" << endl << endl;

	output << setw(INDENT_WIDTH) << "" << getSenderName() << endl;
	output << setw(INDENT_WIDTH) << "" << getSenderAddress() << endl;
	output << setw(INDENT_WIDTH) << "" << getSenderCity() << ", " << getSenderState() << " " << getSenderZipCode() << endl << endl;

	output << setw(INDENT_WIDTH) << "" << "SHIP TO:" << endl;
	output << setw(INDENT_WIDTH) << "" << getRecipientName() << endl;
	output << setw(INDENT_WIDTH) << "" << getRecipientAddress() << endl;
	output << setw(INDENT_WIDTH) << "" << getRecipientCity() << ", " << getRecipientState() << " " << getRecipientZipCode() << endl << endl;
	output << "==============================\n" << endl;

	output << setw(INDENT_WIDTH) << "" << "PACKAGE INFO: " << endl;
	output << setw(INDENT_WIDTH) << "" << "Weight: " << getWeight() << " Oz" << endl;
	output << setw(INDENT_WIDTH) << "" << "Cost per/Oz: $" << getCost() << endl;


	return output.str();
}