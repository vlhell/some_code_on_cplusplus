#include <algorithm>
#include <vector>
using namespace std;

class FunctionPart {
public:
    FunctionPart(char new_oper, double new_val) {
        oper = new_oper;
        val = new_val;
    }
    double Apply(double source_val) const {
        if (oper == '+') {
            return source_val + val;
        } else if (oper == '-') {
            return source_val - val;
        } else if (oper == '*') {
            return source_val * val;
        } else {
            return source_val / val;
        }
    }
    void Invert() {
        if (oper == '+') {
            oper = '-';
        } else if (oper == '-') {
            oper = '+';
        } else if (oper == '*') {
            oper = '/';
        } else {
            oper = '*';
        }
    }
private:
    char oper;
    double val;
};



class Function {
public:
    void AddPart(char oper, double val) {
        parts.push_back({oper, val});
    }
    double Apply(double val) const {
        for (const FunctionPart& part : parts) {
            val = part.Apply(val);
        }
        return val;
    }
    void Invert(){
        for(FunctionPart& part:parts) {
            part.Invert();
        }
        reverse(begin(parts),end(parts));
    }
private:
    vector <FunctionPart> parts;
};