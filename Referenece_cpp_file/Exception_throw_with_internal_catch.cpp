#include <cstdlib>
#include <stdexcept>

class Range {
public:
    explicit Range(const int i): sInt_(i) {
        if(i < 0 || i > 255){
            sInt_ = 0;
            throw std::out_of_range("  small integer. Out of range.");
 	   }
	}	
    operator int() const { return sInt_; }
private:
    size_t sInt_;
};

int main() {

    Range si(-4);
    
    return EXIT_SUCCESS;
}