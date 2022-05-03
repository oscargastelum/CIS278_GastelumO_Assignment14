#pragma once // Assures that the file will not be included multiple times in the current project.

//Header files declarations 

#ifndef OVERNIGHTPACKAGE_H // Will prevent C++ header files from being included multiple times.
#define OVERNIGHTPACKAGE_H // If not already defined, proceed to define header.


//Include:
#include "Package.h" // include Package.h header file 


using namespace std;// eliminates the need to repeat the std:: prefix
#include <iostream> // This class inherits all members from its two parent classes istream and ostream, 			        
#include <string> // to use the string data type
#include <iomanip>
#include <sstream>


class OvernightPackage : public Package {


	// public methods 
public:
	//constructors & destructors 
	OvernightPackage();

	virtual ~OvernightPackage();

	using Package::Package;

	//constructor 
	OvernightPackage(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&,
		const std::string&, const std::string&,const std::string&, const std::string&, const std::string&,
		double, double, double);


	//setters and getters 
	void setOvernightFeeAmount(double);
	double getOvernightFeeAmount() const;


	//overload calculatecost
	virtual double calculateCost() const override;
	virtual std::string toString() const override;

	//private fields 
private:
	virtual std::string getPackageType() const override;
	double overnightFee{ 0 };
	const std::string packageType{ "OVERNIGHT PACKAGE" };
};


#endif // end if condition 