from math import *
from fractions import Fraction

def getABCvalues(trinomial): #get a b c values from the user
	xIndex = 0 
	num = trinomial[xIndex] 
	
	if num == "-": 
		xIndex = 1
		negative = -1
		num = trinomial[xIndex]
		
	else: negative = 1 
		
	infoA = collectValue(1, negative, xIndex, num, trinomial)
	aValue = infoA[0]
	
	if aValue == 0: aValue == 1
		
	infoB1 = collectValue(3, 1, infoA[1], infoA[2], trinomial)
	infoB2 = collectValue(4, infoB1[0], infoB1[1], infoB1[2], trinomial)
	bValue = infoB2[0]
	infoC = collectValue(2, 1, infoB2[1], infoB2[2], trinomial)
	cValue = int(trinomial[infoC[1]:]) * infoC[0]
	if aValue == 0: aValue = 1
	return [aValue, bValue, cValue]
	
def getCommonFactor(aValue, bValue, cValue):
	found = False
	
	if aValue < 0: aValue *= -1
	if bValue < 0: bValue *= -1
	if cValue < 0: cValue *= -1
			
	if cValue == 0:
		if aValue == 1: 
			gcf = 1
			found = True
			
		else: 
			if aValue < cValue: sNum = aValue
			else: sNum = cValue

			for num in range(2, sNum + 1):
				if aValue % num == 0 and bValue % num == 0 and cValue % num == 0: 
					found = True
					gcf = num 
					
			if found == False:
				gcf = 1
				found = True
	else:
		if aValue < bValue and aValue < cValue: sNum = aValue
		elif bValue < aValue and bValue < cValue: sNum = bValue
		else: sNum = cValue

		for num in range(2, sNum + 1):
			if aValue % num == 0 and bValue % num == 0 and cValue % num == 0: 
				found = True
				gcf = num 
			
	if found == False: gcf = "none"
	return gcf
	
def collectValue(type, negative, xIndex, num, trinomial):
	numList = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
	
	if type in [1, 4]: 
		if type == 4:
			num = trinomial[xIndex]
			if num == "2":
				value = int(num)
				xIndex += 1
			
			else: value = 0
		else: value = 0
			
		while num in numList:
			value *= 10
			value += int(num)
			xIndex += 1
			num = trinomial[xIndex]

		return value * negative, xIndex, num
		
	if type == 2: list = ["x", "X", " ", "+", "-"]
	if type == 3: list = ["x", "X", "^", " ", "+", "2", "-"]
	if type in [2, 3]:
		two = False
		
		while num in list:
			if num == "-" or negative == -1: negative = -1
			else: negative = 1
			if type == 3:
				if num == "2" and two == False: 
					two = True  	  
			xIndex += 1
			num = trinomial[xIndex]
		if two == True:
			return negative, xIndex, "2"
		else: return negative, xIndex, num
			
def factorTrinomial(ABCvalues):
	aValue = ABCvalues[0]
	bValue = ABCvalues[1]
	cValue = ABCvalues[2]
	commonFactor = getCommonFactor(aValue, bValue, cValue)
	
	if commonFactor != "none":
		cf = True
		if aValue < 0:
			commonFactor *= -1
		aValue /= commonFactor
		bValue /= commonFactor
		cValue /= commonFactor
		if commonFactor == 1: commonFactor = "x"
		else: commonFactor = str(commonFactor) + "x"
			
		if cValue == 0:
			if bValue < 0: 
				operator = " - "
				bValue *= -1
			else: operator = " + "
				
			if aValue == 1: aValue = "x"
			else: aValue = str(aValue) + "x"
							
		elif bValue == 0: "hi"

		else:
			if delta_failed(aValue, bValue, cValue) == False:
				if aValue == 1: int_x(aValue,bValue,cValue, commonFactor)
				else: decimal_x(aValue,bValue,cValue)
	else:
		if delta_failed(aValue,bValue,cValue) == True: print("Can't be factored")
		else: 
			if aValue == 1: int_x(aValue,bValue,cValue, commonFactor)
			else: decimal_x(aValue,bValue,cValue, commonFactor)

def delta_failed(a, b, c):
	if (b**2 - (4*a*c)) < 0: return True
	else: return False

# Case1: Integer    
def int_x(a,b,c,commonFactor):
	if Fraction((-b + sqrt(b**2-4*a*c)) / (2*a)) != int(Fraction((-b + sqrt(b**2-4*a*c))/(2*a))):
		print("can't be factored")
	else:
		x1 = int((-b + sqrt(b**2-4*a*c))/(2*a))
		x2 = int((-b - sqrt(b**2-4*a*c))/(2*a))
		x1 = -1*x1
		x2 = -1*x2
  
  
	if commonFactor == "none":
		if x1 < 0:
			if x2 < 0:
				print("(x-" + str(abs(x1)) + ")" +
					"(x-" + str(abs(x2)) + ")")
			else: 
				print("(x-" + str(abs(x1)) + ")" +
				 "(x+" + str(abs(x2)) + ")")
		else:
			if x2 < 0:
				print("(x+" + str(abs(x1)) + ")" + "(x-" + str(abs(x2)) + ")")
				
			else:
				print("(x+" + str(abs(x1)) + ")" + "(x+" + str(abs(x2)) + ")")
    
  
	if commonFactor != "none":
		if x1 < 0:
			if x2 < 0:
				print(commonFactor + "(x-" + str(abs(x1)) + ")" +
					"(x-" + str(abs(x2)) + ")")
			else: 
				print(commonFactor + "(x-" + str(abs(x1)) + ")" +
				 "(x+" + str(abs(x2)) + ")")
		else:
			if x2 < 0:
				print(commonFactor + "(x+" + str(abs(x1)) + ")" + "(x-" + str(abs(x2)) + ")")
				
			else:
				print(commonFactor + "(x+" + str(abs(x1)) + ")" + "(x+" + str(abs(x2)) + ")")
    
    
       
					
def decimal_x(a,b,c, trinomial):
	x1 = int(-b + sqrt(b**2-4*a*c))
	y =  int(2*a)
	x2 = int(-b - sqrt(b**2-4*a*c))

	d1 = gcd(x1, y)
	d2 = gcd(x2, y)
	x1 = x1 // d1
	x2 = x2 // d2
	y1 = y // d1
	y2 = y // d2
	trinomial += ("(" + str(y1) + "x+" + str(-1*x1) + ")" +
		  "(" + str(y2) + "x+" + str(-1*x2) + ")")