#pragma once // Assures that the file will not be included multiple times in the current project.

//Header files declarations 

#ifndef PACKAGE_H // Will prevent C++ header files from being included multiple times.
#define PACKAGE_H // If not already defined, proceed to define header.


using namespace std; // eliminates the need to repeat the std:: prefix
#include <string> // to use the string data type
#include <iostream> // This class inherits all members from its two parent classes istream and ostream, 
#include <iomanip>
#include <sstream>

class Package {


	// public methods 
public:
	//constructors & destructors 
	Package();
	Package(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&,
		    const std::string&, const std::string&, const std::string&, const std::string&, const std::string&,
		    double, double);

	virtual ~Package() = default; // virtual destructor 

	void setSenderName(const std::string&);
	std::string getSenderName() const;



	void setSenderAddress(const std::string&);
	std::string getSenderAddress() const;

	void setSenderCity(const std::string&);
	std::string getSenderCity() const;

	void setSenderState(const std::string&);
	std::string getSenderState() const;

	void setRecipientName(const std::string&);
	std::string getRecipientName() const;

	void setRecipientAddress(const std::string&);
	std::string getRecipientAddress() const;

	void setRecipientCity(const std::string&);
	std::string getRecipientCity() const;

	void setRecipientState(const std::string&);
	std::string getRecipientState() const;



	void setWeight(const double);
	double getWeight() const;

	void setCost(const double);
	double getCost() const;

	void setSenderZipCode(const std::string&);
	std::string getSenderZipCode() const;

	void setRecipientZipCode(const std::string&);
	std::string getRecipientZipCode() const;


	virtual double calculateCost() const; 
	virtual std::string toString() const; // toString() method


	//private fields 
private:
	std::string setValidZipCode(const std::string&) const;
	virtual std::string getPackageType() const;


	std::string senderName;
	std::string senderAddress;
	std::string senderCity;
	std::string senderState;
	std::string senderZipCode{ "00000" }; //string and not int; no calculations made if with int values.

	std::string recipientName;
	std::string recipientAddress;
	std::string recipientCity;
	std::string recipientState;
	std::string recipientZipCode{ "00000" }; //string and not int; no calculations made if with int values.

	std::string zipCode{ "00000" };

	double weightOz{ 0 }; // weight in oz
	double costPerOunce{ 0 };

	const std::string packageType{ "PACKAGE" };

};


#endif // end if condition 