#include <iostream>
#include <string>
#include <cctype>

const int MAX_NUMBERS = 25;

bool convertOperand(const std::string& word, int num[]){
    if(word.size() > MAX_NUMBERS || word.empty()){
        return false;
    }

    for(int i = 0; i < MAX_NUMBERS; i++){
        num[i] = 0;
    }

    int limit = static_cast<int>(word.size());


    for(int i = 0; i < limit; i++){
        if(!isdigit(word[i])){
            return false;
        }
        num[i] = word[limit - 1 - i] - '0';
    }
    return true;
}

// returns true when no overflow 
bool addOperands(const int number1[], const int number2[], int result[]){
    int carry = 0; 

    // fill result array with 0's
    for(int i = 0; i < MAX_NUMBERS; i++){
        result[i] = 0;
    }

    for(int i = 0; i < MAX_NUMBERS; i++){
        int sum = number1[i] + number2[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }

    // if we reach 25 and still have a carry, it's overflowing
    if(carry > 0){
        return false;
    }
    return true;
}


bool subOperands(const int number1[], const int number2[], int result[]){
    // First, verify that number1 is not smaller than number2 to prevent negative results.
    bool isLess = false;
    for(int i = MAX_NUMBERS - 1; i >= 0; i--){
        if(number1[i] < number2[i]){
            isLess = true;
            break; 
        } else if (number1[i] > number2[i]){
            break; 
        }
    }
    
    if (isLess) {
        return false;
    }

    int borrow = 0; 

    // fill result array with 0's
    for(int i = 0; i < MAX_NUMBERS; i++){
        result[i] = 0;
    }

    // Perform the subtraction
    for(int i = 0; i < MAX_NUMBERS; i++){
        int diff = number1[i] - number2[i] - borrow;
        
        if(diff < 0){
            diff += 10;  
            borrow = 1;  
        } else {
            borrow = 0;
        }
        result[i] = diff;
    }

    return true;
}

void outputResult(const int result[]){
    bool leadingZero = true;

    for(int i = MAX_NUMBERS - 1; i >= 0; i--){
        if(result[i] != 0){
            leadingZero = false;
        }

        if(!leadingZero){
            std::cout << result[i];
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

        int number1Array[MAX_NUMBERS] = {0};
        int number2Array[MAX_NUMBERS] = {0};
        int resultArray[MAX_NUMBERS] = {0};

        bool number1Valid = convertOperand(number1, number1Array);
        bool number2Valid = convertOperand(number2, number2Array);

        if(!number1Valid || !number2Valid){
            std::cout << "Invalid operand(s).\n\n";
            continue;
        }


        if (signOperator == "+") {
            bool success = addOperands(number1Array, number2Array, resultArray);
            if(success){
                std::cout << number1 << " + " << number2 << " = ";
                outputResult(resultArray);
                std::cout << std::endl << std::endl;
            } else{
                std::cout << number1 << " + " << number2 << " = overflow\n\n";
            }
        } 
        else if (signOperator == "-") {
            bool success = subOperands(number1Array, number2Array, resultArray);
            if(success){
                std::cout << number1 << " - " << number2 << " = ";
                outputResult(resultArray);
                std::cout << std::endl << std::endl;
            } else{
                std::cout << number1 << " - " << number2 << " = result is negative\n\n";
            }
        }
    }

    return 0; 
}