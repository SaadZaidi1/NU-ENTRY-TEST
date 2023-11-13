#include <stdio.h>

void question() {
    int i;
    char *ques[30] = {
        "1. What is the derivative of ln(x) with respect to x?\n   A) 1/x\n   B) x\n   C) 0\n   D) e^x\n   Answer: A) 1/x",
        "2. Which of the following is a prime number?\n   A) 10\n   B) 25\n   C) 29\n   D) 35\n   Answer: C) 29",
        "3. What is the value of p (pi) to three decimal places?\n   A) 3.142\n   B) 3.141\n   C) 3.1416\n   D) 3.140\n   Answer: A) 3.142",
        "4. If a triangle has angles measuring 30 degrees, 60 degrees, and 90 degrees, what type of triangle is it?\n   A) Isosceles\n   B) Scalene\n   C) Equilateral\n   D) Right-angled\n   Answer: D) Right-angled",
        "5. What is the value of the square root of 144?\n   A) 12\n   B) 14\n   C) 10\n   D) 11\n   Answer: A) 12",
        "6. If f(x) = 2x^2 + 3x - 1, what is the derivative of f(x) with respect to x?\n   A) 4x + 3\n   B) 2x^2 + 3x - 1\n   C) 2x + 3\n   D) 4x^2 + 3\n   Answer: A) 4x + 3",
        "7. What is the area of a circle with a radius of 5 units?\n   A) 10 square units\n   B) 25 square units\n   C) 50 square units\n   D) 5p square units\n   Answer: B) 25 square units",
        "8. If log(base 2) 16 = 4, what is log(base 2) 64?\n   A) 4\n   B) 5\n   C) 6\n   D) 3\n   Answer: B) 6",
        "9. In a geometric progression, if the first term is 2 and the common ratio is 3, what is the fourth term?\n   A) 6\n   B) 18\n   C) 9\n   D) 24\n   Answer: B) 18",
        "10. What is the solution to the equation 2x^2 + 5x - 3 = 0?\n    A) x = 1, x = -3/2\n    B) x = 3, x = -1/2\n    C) x = 1, x = -1/2\n    D) x = 3, x = -3/2\n   Answer: C) x = 1, x = -1/2",
        "11. What is the square of 9?\n   A) 63\n   B) 81\n   C) 72\n   D) 64\n   Answer: B) 81",
        "12. If a triangle has sides measuring 3 cm, 4 cm, and 5 cm, what type of triangle is it?\n   A) Equilateral\n   B) Isosceles\n   C) Scalene\n   D) Right-angled\n   Answer: D) Right-angled",
        "13. What is the value of 5! (5 factorial)?\n   A) 20\n   B) 120\n   C) 25\n   D) 60\n   Answer: B) 120",
        "14. If x = 4 and y = 2, what is the value of x^2 + 2xy + y^2?\n   A) 12\n   B) 16\n   C) 36\n   D) 64\n   Answer: D) 64",
        "15. Solve for x: 2x - 3 = 7.\n   A) x = 4\n   B) x = 5\n   C) x = 6\n   D) x = 7\n   Answer: B) x = 5",
        "16. What is the perimeter of a rectangle with length 10 cm and width 5 cm?\n   A) 10 cm\n   B) 20 cm\n   C) 30 cm\n   D) 50 cm\n   Answer: B) 20 cm",
        "17. Find the greatest common divisor (GCD) of 24 and 36.\n   A) 4\n   B) 6\n   C) 8\n   D) 12\n   Answer: B) 6",
        "18. If the selling price of an item is $150, and the cost price is $120, what is the profit made?\n   A) $20\n   B) $30\n   C) $40\n   D) $150\n   Answer: B) $30",
        "19. What is the value of v(25) + v(16)?\n   A) 9\n   B) 7\n   C) 11\n   D) 8\n   Answer: B) 7",
        "20. If a circle has a radius of 7 cm, what is its circumference (use p = 3.14)?\n    A) 14.28 cm\n    B) 22 cm\n    C) 43.96 cm\n    D) 44 cm\n    Answer: B) 22 cm",
        "21. What comes next in the sequence: 2, 4, 8, 16, ____?\n   A) 24\n   B) 32\n   C) 48\n   D) 64\n   Answer: B) 32",
        "22. If three cats can catch three mice in three minutes, how many cats are needed to catch 100 mice in 100 minutes?\n   A) 1 cat\n   B) 2 cats\n   C) 3 cats\n   D) 100 cats\n   Answer: A) 1 cat",
        "23. Which letter of the alphabet comes next in the series: J, F, M, A, M, J, ____?\n   A) J\n   B) F\n   C) M\n   D) J\n   Answer: A) J",
        "24. A farmer has 17 sheep, and all but 9 die. How many sheep does the farmer have left?\n   A) 17\n   B) 8\n   C) 9\n   D) 26\n   Answer: C) 9",
        "25. If a plane crashes on the border of the United States and Canada, where do they bury the survivors?\n   A) The United States\n   B) Canada\n   C) Nowhere, survivors are not buried\n   D) Both the United States and Canada\n   Answer: C) Nowhere, survivors are not buried"
        "26. What is the definition of a palindrome?\n   A) A type of poem\n   B) A word or phrase that reads the same backward as forward\n   C) A type of grammar rule\n   D) A foreign language\n   Answer: B) A word or phrase that reads the same backward as forward",
        "27. Which part of speech is used to describe a verb, adjective, or adverb?\n   A) Noun\n   B) Pronoun\n   C) Conjunction\n   D) Adverb\n   Answer: D) Adverb",
        "28. What is the correct plural form of 'child'?\n   A) Childs\n   B) Childrens\n   C) Childs' \n   D) Children\n   Answer: D) Children",
        "29. Which of the following is an example of an indefinite article?\n   A) The\n   B) An\n   C) In\n   D) Is\n   Answer: B) An",
        "30. What is the term for a group of words that expresses a complete thought and typically includes a subject and a predicate?\n   A) Paragraph\n   B) Clause\n   C) Phrase\n   D) Sentence\n   Answer: D) Sentence"
    };
    
    for (i = 0; i < 30; i++) 
	{
        printf("%s\n\n", ques[i]);
    }
}

int main() {
    question();
    return 0;
}

