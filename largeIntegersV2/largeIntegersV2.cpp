#include <iostream>
#include <string>
#include <vector>
#include <cctype>

const int MAX_NUMBERS = 25;

bool convertOperand(const std::string& word, std::vector<int>& num){

    if(word.size() > MAX_NUMBERS || word.empty()){
        return false;
    }

    //fill vector with zero
    for(int i = 0; i < MAX_NUMBERS; i++){
        num.at(i) = 0;
    }

    int limit = static_cast<int>(word.size());

    // checks to see if letters involved
    for(int i = 0; i < limit; i++){

        if(!isdigit(word.at(i))){
            return false;
        }
        num.at(i) = word[limit - 1 - i] - '0';
    }
    return true;
}

// returns true when no overflow 
bool addOperands(const std::vector<int>& number1, const std::vector<int>& number2, std::vector<int>& result){

    int carry = 0; 

    //fill result vector with 0's
    for(int i = 0; i < MAX_NUMBERS; i++){
        result.at(i) = 0;
    }

    for(int i = 0; i < MAX_NUMBERS; i++){
        int sum = number1.at(i) + number2.at(i) + carry;
        result.at(i) = sum % 10;
        carry = sum / 10;
    }

    // if we reach 25 and still have a carry, it's overflowing
    if(carry > 0){
        return false;
    }
    return true;
}

bool subOperands(const std::vector<int>& number1, const std::vector<int>& number2, std::vector<int>& result){
    bool isLess = false;

    for(int i = MAX_NUMBERS - 1; i >= 0; i--){
        if(number1.at(i) < number2.at(i)){
            isLess = true;
            break;
        } else if(number1.at(i) > number2.at(i)){
            break;
        }
    }

    if(isLess){
        return false;
    }

    int borrow = 0; 
    for(int i = 0; i < MAX_NUMBERS; i++){
        result.at(i) = 0;
    }

    // Subtract numbers
    for(int i = 0; i < MAX_NUMBERS; i++){
        int diff = number1.at(i) - number2.at(i) - borrow;
        
        if(diff < 0){
            diff += 10;  
            borrow = 1;  
        } else {
            borrow = 0;
        }
        result.at(i) = diff;
    }

    return true;


}

void outputResult(const std::vector<int>& result){
    bool leadingZero = true;

    for(int i = MAX_NUMBERS - 1; i >= 0; i--){
        if(result.at(i) != 0){
            leadingZero = false;
        }

        if(!leadingZero){
            std::cout << result.at(i);
        }
    }
    if(leadingZero){
            std::cout << 0;
        }

}


int main(){

   std::string number1;
   std::string signOperator; 
   std::string number2;

   while(true){

        std::cout << "Enter an expression -->  ";

        std::cin >> number1 >> signOperator >> number2;

        if(number1 == "0" && signOperator == "%" && number2 == "0"){
            std::cout << "Thank you for using my program." << std::endl;
            break;
        }

        if(signOperator != "+" && signOperator != "-"){
            std::cout << "Invalid operator." << std::endl << std::endl;
            continue;
        }

        //set up vectors
        std::vector<int> number1Vector(MAX_NUMBERS, 0);
        std::vector<int> number2Vector(MAX_NUMBERS, 0);
        std::vector<int> resultVector(MAX_NUMBERS, 0);

        bool number1Valid = convertOperand(number1, number1Vector);
        bool number2Valid = convertOperand(number2, number2Vector);

        if(!number1Valid || !number2Valid){

            std::cout << "Invalid operand(s).\n\n";
            continue;
        }

        // Branch logic based on the operator entered
        if (signOperator == "+") {
            bool success = addOperands(number1Vector, number2Vector, resultVector);
            if(success){
                std::cout << number1 << " + " << number2 << " = ";
                outputResult(resultVector);
                std::cout << std::endl << std::endl;
            } else{
                std::cout << number1 << " + " << number2 << " = overflow\n\n";
            }
        } 
        else if (signOperator == "-") {
            bool success = subOperands(number1Vector, number2Vector, resultVector);
            if(success){
                std::cout << number1 << " - " << number2 << " = ";
                outputResult(resultVector);
                std::cout << std::endl << std::endl;
            } else{
                std::cout << number1 << " - " << number2 << " = result is negative\n\n";
            }
        }
    }

   return 0; 
}