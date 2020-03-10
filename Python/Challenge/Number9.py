# Class


class Complex(complex):
    def __init__(self, real, imag=0):
        super().__init__()

    def __add__(self, no):
        return Complex(self.real + no.real, self.imag + no.imag)

    def __sub__(self, no):
        return Complex(self.real - no.real, self.imag - no.imag)

    def __mul__(self, no):
        return Complex(self.real * no.real - self.imag * no.imag,
                       self.real * no.imag + self.imag * no.real)

    def __truediv__(self, no):
        return Complex(complex.__truediv__(self, no))

    def mod(self):
        return Complex(complex.__abs__(self))

    def __str__(self):
        if self.imag == 0:
            result = "%.2f+0.00i" % self.real
        elif self.real == 0:
            if self.imag >= 0:
                result = "0.00+%.2fi" % self.imag
            else:
                result = "0.00-%.2fi" % (abs(self.imag))
        elif self.imag > 0:
            result = "%.2f+%.2fi" % (self.real, self.imag)
        else:
            result = "%.2f-%.2fi" % (self.real, abs(self.imag))
        return result


c = map(float, input().split())
d = map(float, input().split())
x = Complex(*c)
y = Complex(*d)
print(*map(str, [x+y, x-y, x*y, x/y, x.mod(), y.mod()]), sep='\n')
