#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <stdlib.h>
#include <cstddef>

using namespace std;




void Choices(string &AllQuestions, int i , list<string> &Questions)
{
	const char initial = 'A';
	string ChoiceQuestion = Questions.back();
	Questions.pop_back();

	for (int x = 0; x < i; x++)
	{
		//initial = toascii(initial) + x;
		ChoiceQuestion = ChoiceQuestion + "\n" + char(initial+x)  + ") " + AllQuestions.substr(0, AllQuestions.find("\n"));
		AllQuestions = AllQuestions.substr(AllQuestions.find("\n") + 1, AllQuestions.length());
	}
	Questions.push_back(ChoiceQuestion);
	
}



void GetMultipleChoiceQuestion(string &AllQuestions, list<int> &QuestionsMarks, list<string> &Modelanswers, list<string> &Questions)
{
	
	int NumberOfChoices;
	QuestionsMarks.push_back(atoi(AllQuestions.substr(0, AllQuestions.find("\n")).c_str()));
	AllQuestions = AllQuestions.substr(AllQuestions.find("\n") + 1, AllQuestions.length());
	Questions.push_back(AllQuestions.substr(0, AllQuestions.find("\n")));
	AllQuestions = AllQuestions.substr(AllQuestions.find("\n") + 1, AllQuestions.length());
	NumberOfChoices = atoi(AllQuestions.substr(0, AllQuestions.find("\n")).c_str());
	AllQuestions = AllQuestions.substr(AllQuestions.find("\n") + 1, AllQuestions.length());
	Choices(AllQuestions, NumberOfChoices , Questions);
	Modelanswers.push_back(AllQuestions.substr(0, AllQuestions.find("\n")));
	AllQuestions = AllQuestions.substr(AllQuestions.find("\n") + 1, AllQuestions.length());

}



void GetQuestions(string &AllQuestions , list<string> &QuestionType , list<int> &QuestionsMarks , list<string> &Modelanswers , list<string> &Questions)
{
	bool flag = true;
	if (AllQuestions == "")
	{
		flag = false;
	}
	if ( flag == true)
	{
		
		QuestionType.push_back(AllQuestions.substr(0, AllQuestions.find(" ")));
		AllQuestions = AllQuestions.substr(AllQuestions.find(" ") + 1, AllQuestions.length());
		if (QuestionType.back() == "MC")
		{
			GetMultipleChoiceQuestion(AllQuestions, QuestionsMarks, Modelanswers, Questions);
		}
		else
		{
			QuestionsMarks.push_back(atoi(AllQuestions.substr(0, AllQuestions.find("\n")).c_str()));
			AllQuestions = AllQuestions.substr(AllQuestions.find("\n") + 1, AllQuestions.length());
			Questions.push_back(AllQuestions.substr(0, AllQuestions.find("\n")));
			AllQuestions = AllQuestions.substr(AllQuestions.find("\n") + 1, AllQuestions.length());
			Modelanswers.push_back(AllQuestions.substr(0, AllQuestions.find("\n")));
			AllQuestions = AllQuestions.substr(AllQuestions.find("\n") + 1, AllQuestions.length());

		}
		GetQuestions(AllQuestions, QuestionType, QuestionsMarks, Modelanswers, Questions);
	}

}



bool AnswerCheck(string answer, list<string> &QuestionType, list<int> &QuestionsMarks, list<string> &Modelanswers , int &score)
{

	if (Modelanswers.front().compare(answer) == 0)
	{
		Modelanswers.pop_front();
		score += QuestionsMarks.front();
		QuestionsMarks.pop_front();
		QuestionType.pop_front();

		return true;
	}
	else
	{
		Modelanswers.pop_front();
		score -= QuestionsMarks.front();
		QuestionsMarks.pop_front();
		QuestionType.pop_front();

		return false;
	}
}


int main()
{
	// ............Declaration
	fstream File;
	stringstream StrStream;
	string FullName, FName, LName, Path, Input, answer;
	list<string> QuestionType, Modelanswers, Question, UserAnswers;
	list<int> QuestionsMarks;
	int NumberOfQuestions, Length, MaxNumberOfQuestions;
	int i = 0, score = 0;
	int index;
	bool AnswerState;

	cout << "Please Enter your First Name : \n";
	cin >> FName;
	cout << "Please Enter your Last Name : \n";
	cin >> LName;
	FullName = FName + " " + LName;
	cout << "Please Enter your File name: \n";
	cin >> Path;

	// ........ open the file & put it in string
	try
	{
		File.open(Path.c_str());
		StrStream << File.rdbuf();
		Input = StrStream.str();
		MaxNumberOfQuestions = atoi(Input.substr(0, Input.find("\n")).c_str());
		Input = Input.substr(Input.find("\n") + 1, Input.length());
	}
	catch (exception e)
	{
		cout << " An Error Occured , Make sure of the File Name \n";
	
	}


	if (File.is_open() > 0 )
	{
		// .......... Number of questions he wants to be asked 
		cout << "How many Questions do you like to practice ? \n";
		cin >> NumberOfQuestions;


		// ........... checking if questions are enough or not , if yes .. start asking
		if (NumberOfQuestions <= MaxNumberOfQuestions)
		{
			GetQuestions(Input, QuestionType, QuestionsMarks, Modelanswers, Question);
			while (i < NumberOfQuestions)
			{
				cout << Question.front() << "\n";
				Question.pop_front();
				cout << "1.Answer the question   2.Skip Question \n";
				cin >> index;
				switch (index)
				{
				case 1:
					cout << "Your answer is: \n";
					cin >> answer;
					cout << "\n";
					AnswerState = AnswerCheck(answer, QuestionType, QuestionsMarks, Modelanswers, score);
					cout << "Score = " << score << "\n";
					break;


				case 2:
					cout << "Score = " << score << "\n";
					QuestionType.pop_front();
					QuestionsMarks.pop_front();
					Modelanswers.pop_front();

				}


				i += 1;

			}

		}


		else
		{
			cout << " There is no enough questions , Our maximum number of questions is ";
			cout << MaxNumberOfQuestions << "\n" ;
		}

		cout << "End Of Questions" << endl;
		
	}
	
	else
	{
		cout << " An Error Occured , Make sure of the File Name " <<endl;
	}

	cout << "... Press Any Key To Continue ..." << endl;
	//_getch();
}
