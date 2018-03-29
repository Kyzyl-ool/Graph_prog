#include <cstdlib>
#define MATH_FUNCTION_DEFAULT_AMOUNT_OF_REFERENCE_POINTS 128

typedef unsigned int uint;

class math_function
{
private:
	double* ref_points;
	uint amount;
	
public:
	math_function();
	~math_function();
	
	uint amount_of_points();
	void add_point(double value, double argument);
	void remove_point(uint number);
	
	void deploy_graphic();
};

math_function::math_function()
{
	ref_points = (double* )calloc(MATH_FUNCTION_DEFAULT_AMOUNT_OF_REFERENCE_POINTS, sizeof(double));
}

math_function::~math_function()
{
	free(ref_points);
}

uint math_function::amount_of_points()
{
	return amount;
}

void math_function::add_point(double value, double argument)
{
	
}

void math_function::remove_point(uint number)
{
	
}

void math_function::deploy_graphic()
{
	
}
