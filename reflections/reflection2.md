# Reflection 2
My goal for this sprint was to better balance my project work and my exercises. Additionally, I, as well as my team members, wanted to dedicate more meeting times to project work and not exercises which we could do on our own time.

I think I did a good job getting my exercises done before the sprint review. However, I felt like I and some of my team fell behind on the project. Our meetings to work on the project were very inconsistent. Also, we had the problem where some members of the team would work on different parts of the project, and no one else would understand the part that the person coded. To fix these problems, we decided during our retrospective to do more pair programming so that, as a team, we would be more of on the same page. As a whole, I think we are behind on our project with all the work we have to get done this following week. This was probably due to our inconsistent meetings. To fix this, we are planning consistent meetings to work on our project at specific times over the next week. 

## Exercises in C
[Exercise 2.5](https://github.com/jag-123/ExercisesInC/tree/master/exercises/ex02.5)

[Exercise 3](https://github.com/jag-123/ExercisesInC/tree/master/exercises/ex03)

[Exercise 4](https://github.com/jag-123/ExercisesInC/tree/master/exercises/ex04)

## ThinkOS Questions
I completed chapters 3 and 4 of TOS this sprint.

[Reading Questions](https://github.com/jag-123/ExercisesInC/blob/master/reading_questions/thinkos.md)

## Exam Question and Solution
Question:
```c
int foo()
{
  char *2Buffer;
  bool b = true;
  if(b)
  {
    char 1Buffer[500];
    2Buffer = new char[500];
   }
}
```
What is a similarity and a difference between the stack and the heap? In the example above, where are 1Buffer and 2Buffer allocated?

Answer: 
Both the stack and heap are stored in a computer's RAM, but the stack is used for static memory allocation (varibales are allocated when the program is compiled) while the heap is used for dynamic memory allocation (varibles are allocated at run time). 1Buffer is allocated on the stack and 2Buffer is allocated on the heap. 
