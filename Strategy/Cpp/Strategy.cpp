#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

//This code is for parking lot mechanism implemented for pricing calculation

enum class VehicleType
{
	HATCHBACK,
	TRUCK,
	SEDAN
};

namespace Pricing
{
	constexpr double HATCHBACK_PRICE = 2.0;
	constexpr double TRUCK_PRICE = 4.5;
	constexpr double SEADAN_PRICE = 3.0;
}


class TicketCalculatorStrategy
{
public:
	virtual double calculateTicketPricing(int parkingTime) = 0;
	virtual ~TicketCalculatorStrategy() = default;
};

class HatchBackTicketCalculator : public TicketCalculatorStrategy
{
public:
	double calculateTicketPricing(int parkingTime) override
	{
		return parkingTime * Pricing::HATCHBACK_PRICE;
	}
};

class TruckTicketCalculator : public TicketCalculatorStrategy
{
public:
	double calculateTicketPricing(int parkingTime) override
	{
		return parkingTime * Pricing::TRUCK_PRICE;
	}
};

class SedanTicketCalculator : public TicketCalculatorStrategy
{
public:
	double calculateTicketPricing(int parkingTime) override
	{
		return parkingTime * Pricing::SEADAN_PRICE;
	}
};

class ParkingLot
{
public:
	void setTicketCalculatorStrategy(VehicleType Type)
	{
		switch (Type)
		{
		case VehicleType::HATCHBACK:
			ticketCalculatorStrategy = std::make_unique<HatchBackTicketCalculator>();
			break;
		case VehicleType::TRUCK:
			ticketCalculatorStrategy = std::make_unique<TruckTicketCalculator>();
			break;
		case VehicleType::SEDAN:
			ticketCalculatorStrategy = std::make_unique<SedanTicketCalculator>();
			break;
		default:
			break;
		}
	}

	double calculateTicketPrice(int parkingTime)
	{
		return ticketCalculatorStrategy->calculateTicketPricing(parkingTime);
	}
private:
	std::unique_ptr<TicketCalculatorStrategy>ticketCalculatorStrategy;
};

int main()
{
	ParkingLot parkinglot;
	std::string ivehicleType = "";
	int parkingTime = 0;

	std::cout << "Enter vehicle type (hatchback, truck, sedan): ";
	std::cin >> ivehicleType;
	std::cout << "Enter parking time (in hours): ";
	std::cin >> parkingTime;

	VehicleType VT = VehicleType::HATCHBACK; // Default

	if (ivehicleType == "hatchback") {
		VT = VehicleType::HATCHBACK;
	}
	else if (ivehicleType == "truck") {
		VT = VehicleType::TRUCK;
	}
	else if (ivehicleType == "sedan") {
		VT = VehicleType::SEDAN;
	}
	else {
		std::cout << "Invalid vehicle type." << std::endl;
		return EXIT_FAILURE;
	}

	try {
		parkinglot.setTicketCalculatorStrategy(VT);

		double ticketPrice = parkinglot.calculateTicketPrice(parkingTime);
		std::cout << "Ticket Pricing : " << ticketPrice << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

}