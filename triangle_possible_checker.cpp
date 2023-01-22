#include<iostream>
#include<cmath> // somehow works even without this (SOLVED: VISUAL STUDIO INCLUDES CMATH IN IOSTREAM)

enum Triangle { EQUILATERAL, ISOSCELES, SCALENE, RIGHT_ANGLE/*, NONE */}; // declare Triangle data type with different types
bool is_triangle(float, float, float, int&);




int main() {

	int type;

	float A, B, C;

	std::cout << "To conclude if a triangle can be made, provide 3 side lengths\n"
		<< "Side A: ";
	std::cin >> A;
	std::cout << "Side B: ";
	std::cin >> B;
	std::cout << "Side C: ";
	std::cin >> C;

	if (is_triangle(A, B, C, type))
	{
		switch (type)
		{

		case EQUILATERAL:

			std::cout << "With the provided lengths, an equilateral type triangle can be made.";
			break;


		case RIGHT_ANGLE:

			std::cout << "With the provided lengths, a right angle type triangle can be made.";
			break;


		case ISOSCELES:

			std::cout << "With the provided lengths, an isoceles type triangle can be made.";
			break;


		case SCALENE:

			std::cout << "With the provided lengths, a scalene type triangle can be made.";
			break;

		}
	}

	else
	{
		std::cout << "With the provided lengths, a triangle could not be made.";
	}




	return 0;
}


bool is_triangle(float A_f, float B_f, float C_f, int &type_f) {

	if (A_f == 0 || B_f == 0 || C_f == 0)
	{
		//type_f = NONE;
		return false;
	}

	

	else if (A_f + B_f > C_f || A_f + C_f > B_f || B_f + C_f > A_f)
	{
		float e2 = 2.0;

		if (A_f == B_f && A_f == C_f)
		{
			type_f = EQUILATERAL;
		}

		else if (pow(A_f, e2) + pow(B_f, e2) == pow(C_f, e2) || pow(A_f, e2) + pow(C_f, e2) == pow(B_f, e2) || pow(B_f, e2) + pow(C_f, e2) == pow(A_f, e2))
		{
			type_f = RIGHT_ANGLE;
		}

		else if (A_f == B_f && A_f != C_f || A_f == C_f && A_f != B_f || B_f == C_f && A_f != B_f)
		{
			type_f = ISOSCELES;
		}

		else if (A_f != B_f && A_f != C_f && B_f != C_f)
		{
			type_f = SCALENE;
		}


		return true;
	}


	
	//type_f = NONE;
	return false;
}

// A_f + B_f > C_f || A_f + C_f > B_f || B_f + C_f > A_f  niin on kolmio
// A_f^2 + B_f^2 = C_f^2 niin suorakulmainen
// A_f != B_f && A_f != C_f && B_f != C_f niin epäsäännöllinen
// A_f == B_f && A_f != C_f || A_f == C_f && A_f != B_f || B_f == C_f && A_f != B_f niin tasasivuinen