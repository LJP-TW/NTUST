#include "FormWord.h"
//inputmain2.cpp
int main()
{
	Form form2;
	form2.SetInputWord("calculator");//�]�wInput
	form2.ProcessInputWord();//�B�zInput��T
	form2.SetFileName("word.txt");//�]�w�ɮצW��
	form2.Load_CompaerWord();//Ū�ɨåB���
	form2.PrintFoundWords();//�L�X�ŦX���r
	system("pause");
	return 0;
}