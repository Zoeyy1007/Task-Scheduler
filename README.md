 
# Task Scheduler
 
## Authors: 
* Joshua Citrin https://github.com/ctraino 
* Lyda Taing https://github.com/LydaTaing
* Ashley Vo https://github.com/ashvo 
* Zoey Yang https://github.com/Zoeyy1007
* Taha Mohiuddin https://github.com/Tahamohiuddin

## Importance and Motivation 
This particular project is important to us because as students ourselves, the idea of being organized on the various activities, homework, and tests dates are essential to doing well in school. Working on this project closely aligns to our own necessities are students, which we can therefore utilized in our personal lives in the future. As we are implementing different categories of tasks, this project can be personalized to an individual. 

## Tool and Technologies: 
* C++ (terminal base for interface) 

## input/output
* Input: title, description, classification, date, priority, duration, due date
* Output: Lists of tasks to complete in order, suggested schedules

## Feature
### Overview 
This application allows users to create and manage tasks efficiently. Users can create tasks with attributes such as title, description, classification, priority, duration, and due date. Optional fields are also available to enhance flexibility. Additionally, users can create task lists, grouping multiple tasks together to represent larger projects with subtasks.

Users can display, edit, delete, and undo operations on tasks and task lists. The application provides sorting features based on different criteria and can suggest a schedule based on the user's current tasks. 

### Core Features
* Manage daily tasks and set up reminders
* Create subtasks for tasks
* Sort by deadline (tasks with the sooner due dates appear higher)
* Edit/Delete/Sort tasks
* Add tags to categorize tasks (e.g., "Science Class," "Math Homework")
* Optional 

#### Additional Feature:
 * Assign specific time slots for tasks in a daily schedule
 * Linked Tasks (Once one task is completed, another task is assigned)
  

## User Interface Specification
The Task Scheduler application provides a structured flow for managing events and tasks efficiently. The navigation diagram illustrates how users can interact with the system from the Home Screen and perform various actions on tasks.

### Navigation Diagram
<img width="1045" alt="Screenshot 2025-02-27 at 2 41 08 AM" src="https://github.com/user-attachments/assets/0c8d16a6-fd24-4a4b-9f24-4e9969e4e27c" />


### Screen Layouts
<img width="771" alt="AD_4nXd3yY746di-W9LHkeTGwQUy514UbkJWhY2GCx1RH1O8RoGhUZintlI3sRf-Iws1649zHmfcOweQUFPd5lraz3D9h1j_NpERTWdXq2T1OdYcW-c2Xt2lGCcqIGhGLZ-XK5qkCLhfAQ" src="https://github.com/user-attachments/assets/2679e73f-8121-488c-aa28-b43ee020188e" />

The main menu has two options: create new event, view current schedule or view completed task. Users can also end the program directly by entering 0. 

<img width="771" alt="AD_4nXfMvfk03_GZPOxSOCHx6xax7g_Ot4UBsBcbNDTiZ8J1T9MBarAwNyLakMdklw-mBNm8uSVKxZMgDVFAV9CbgabhmqtrtlnWh51fM9lzgntG3oW-A--OyFbcP5-zvA_ZcI9fFkVI" src="https://github.com/user-attachments/assets/e12dbe04-f91a-4311-9425-db1a5f5495a3" />

If the user selects 1, the program will ask the user for the new event title, time, priority and category. After creating the new event, the user can view the current schedule, create a new event or go to the main menu. 

<img width="771" alt="IMG_6663" src="https://github.com/user-attachments/assets/b7ab4d27-9058-48d9-9ab7-760456cca647" />

If the user selects 2, the program will arrange the current events by category or by priority. The user can select a specific event and edit it. The user can edit the event title, time, delete it or mark it as complete. 



<img width="771" alt="AD_4nXf0z5JgmaG1yXh1Cjgur8gq03JTdwqyjXYw5xm78G5OfaYI80MbWFRje3BqqCA1jdSRyjFaDeJLC0eIpViQyFhX9lAkLkGqMjpS080aJFCkV31S4-JTugDvvZD0jgOgBayTBR1Q4A" src="https://github.com/user-attachments/assets/f0162dea-62b7-479e-ba98-2d4712db0cbd" />

After the user selects a task, the program would ask how the user wants to edit the event. 

<img width="771" alt="IMG_8861" src="https://github.com/user-attachments/assets/582264f6-1e17-4bbe-a55f-f630ee87a98c" />

User can choose to link event or make adjustment on the event inoformation and option to return main menu. 


<img width="771" alt="AD_4nXf0z5JgmaG1yXh1Cjgur8gq03JTdwqyjXYw5xm78G5OfaYI80MbWFRje3BqqCA1jdSRyjFaDeJLC0eIpViQyFhX9lAkLkGqMjpS080aJFCkV31S4-JTugDvvZD0jgOgBayTBR1Q4A" src="https://github.com/user-attachments/assets/ba65d198-2512-4b6e-9f01-029a8684ac62" />

If the user selects 3 from the main menu, the completed task would be displayed. After the completed tasks are displayed, user would return to the main menu. 

## Class Diagram
Data class: This class is responsible for tracking the user’s task statistics related to their productivity levels. The getters and setters will store the user’s average time completion for each task, total task completed, and how many pending tasks they have left.

Schedule class: This class is responsible for tracking how many tasks we can add or remove, the priority level, the name of the schedule, the display, and the duration it will take to complete and whether the schedule is active or inactive.

Task class: This class is responsible for keeping track of the name of the task, priority level, what the task is for, the progress of the task, and whether it is a recurring task or not.

Notification class: This class is responsible for the message the user will receive, the way it is displayed, if the user wants the notification to reappear, and the priority level.

Display Menu class: This class is responsible for keeping track of the selected task number and the display.

User class: This class stores the essential information regarding the name of the user and their ID number. 
![UML](https://github.com/user-attachments/assets/10db852b-30b3-433b-9545-8b6d549bde6d)




 ## Class Diagram Updated 
 ![IMG_0618](https://github.com/user-attachments/assets/0397424f-23c2-4433-82a7-b57d20b470d4)


Deleting notification class: We removed the notification class feature because we wanted to maintain a more 
Clean and efficient codebase. Therefore, we wanted to simplify our feature. This change will streamline the
code and ensure that future updates are easier to implement and maintain. 

Deleting data class: We removed the data class because there is no need for these data features and 
Functions. The idea of getting data from task is already similar to the schedule class. Therefore, removing
This class will follow the single responsibility principle. 

Deleting user class: SInce it is input, terminal-based there is no need for the user class. This is because all of
The inputs and user’s schedules will start from the display menu. Therefore, this removal encourages code
efficiency and simplicity.

Moving functions: We moved the display_categorized() function that initially belonged to the Schedule class
into the DisplayMenu class instead. This is because this function aligns better with the purpose of the 
DisplayMenu class instead of the Schedule class. By moving this into DisplayMenu class we are following
The Single Responsibility Rule where a class should have a single purpose only and not have many purposes.
We deleted the display_full() class in the Schedule class because it was repetitive to what DiplayMenu class’
displaySchedule() had already did



 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
