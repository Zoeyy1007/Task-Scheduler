 
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
### Navigation Diagram
![Navigation Diagram CS100](https://github.com/user-attachments/assets/3413a6f6-595f-4505-a362-9fefb6f8f0cf)

### Screen Layouts
The main menu has two options: create new event or view current schedule
<img width="583" alt="AD_4nXfr9qvs-kPyda7uohh5-JVJlUtwfrBJsA_Lil0GWVOKzqcNKqC49v_GrdI8gz31EfglH19xCUMLcUZbtcaIASHaA75McrKQfB52tqMxeNHSQhgqWzyI2zSlJSBHv3L_ztlkWzMg" src="https://github.com/user-attachments/assets/68df6144-f1cf-4a95-8156-a7c75ead7376" />

If the user selects 1, the program will ask the user for the new event title, time and tag. After creating the new event, the user can view the current schedule, create a new event or go to the main menu.
<img width="621" alt="IMG_6944" src="https://github.com/user-attachments/assets/6910ccf4-998f-4172-afc5-0cfba56cd19a" />

If the user selects 2, the program will arrange the current events by time, and display the events. The user can select a specific event and edit it. The user can edit the event title, time, delete it or mark it as complete. 
<img width="605" alt="AD_4nXfmGAlGx_ZrxaTki-fARDRDXdv5mhZ5LIXRXbtgkL5p3j-rFHg-TSSuBJDrTj8xBovHb_gtlUn7HUOttswVFtji8Wlut0x1-pCrkuDos8o3JkXAOBAZzL2BmfhOAe8Hk1VQxFkYUg" src="https://github.com/user-attachments/assets/b63ede29-32d7-4b38-93f5-449db4904c45" />



## Class Diagram
> draft UML diagram.
![IMG_0607](https://github.com/user-attachments/assets/39cccdd3-fb12-41e9-8882-0453a5fcd341)

 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Peer Evaluation Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
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
 
