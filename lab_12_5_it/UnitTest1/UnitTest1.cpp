#include "pch.h" 
#include <fstream>
#include "CppUnitTest.h"
#include "../lab_12_5_it/Source.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace my_stack_tests
{
    TEST_CLASS(MyStackTests)
    {
    public:

        TEST_METHOD(TestCenterOfMass)
        {
            
            ofstream temp_file("points_temp.txt");
            temp_file << "2.5 3.7" << std::endl;
            temp_file << "1.0 2.0" << std::endl;
            temp_file << "1.4 2.5" << std::endl;
            temp_file << "6.0 3.0" << std::endl;
            temp_file << "4.0 1.0" << std::endl;
            temp_file.close();

          
            Elem* top = nullptr;
            ifstream input_file("points_temp.txt");
            double x, y;
            while (input_file >> x >> y) {
                push(top, x, y);
            }
            input_file.close();

           
            double x_cm, y_cm;
            center_of_mass(top, x_cm, y_cm);
            Assert::AreEqual(2.98, x_cm, 0.01); 
            Assert::AreEqual(2.44, y_cm, 0.01); 

         
            while (top != nullptr) {
                pop(top);
            }
        }
    };
}
