#include <iostream>
#include <exception>

class InvalidPositionException : public std::exception {
    public:
        virtual const char* what() const noexcept override {
            return "A posição informada no vetor é inválida!";
        };
};