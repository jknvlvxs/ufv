#include <iostream>
#include <exception>

class ExcecaoAcimaDeX : public std::exception {
    public:
        virtual const char* what() const noexcept override {
            return "A posição informada no vetor não existe!";
        };
};