#pragma once // Assures that the file will not be included multiple times in the current project.

//Header files declarations 

#ifndef TWODAYPACKAGE_H // Will prevent C++ header files from being included multiple times.
#define TWODAYPACKAGE_H // If not already defined, proceed to define header.


//Include:
#include "Package.h" // include Package.h header file 

using namespace std;// eliminates the need to repeat the std:: prefix
#include <iostream> // This class inherits all members from its two parent classes istream and ostream, 			        
#include <string> // to use the string data type
#include <iomanip>
#include <sstream>


class TwoDayPackage : public Package {


	// public methods 
public:
	//constructors & destructors 
	TwoDayPackage();

	virtual ~TwoDayPackage();


	using Package::Package;

	//constructor 
	TwoDayPackage(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&,
		const std::string&, const std::string&, const std::string&, const std::string&, const std::string&,
		double, double, double);


	//setters and getters 
	void setFeeAmount(double);
	double getFeeAmount() const;

	//overload calculatecost
	virtual double calculateCost(); // calculate cost of shipping 
	virtual std::string toString() const override; //string representation



	//private fields 
private:
	double flatFee{ 0 };
	virtual std::string getPackageType() const override;
	const std::string packageType{ "TWO-DAY PACKAGE" };
};


#endif // end if condition 