Timetable Management System
Description
This C program is a simple Timetable Management System that allows users to create and manage a timetable for subjects over a specified number of days and slots. Users can add subjects, schedule them randomly, display the timetable, change subject slots, or delete subjects. The program is designed to work with a fixed number of days and slots per day.

Features
Add subjects and schedule them randomly.
Display the timetable in a tabular format.
Change the slot of a subject on a specific day.
Delete a subject from a specific slot on a specific day.
Requirements
To run this program, you need:

A C compiler (e.g., GCC)
Standard C libraries
How to Use
Clone this Git repository to your local machine:

shell
Copy code
git clone <repository_url>
Navigate to the project directory:

shell
Copy code
cd timetable-management-system
Compile the program using your C compiler. For example, using GCC:

shell
Copy code
gcc timetable.c -o timetable
Run the program:

shell
Copy code
./timetable
Follow the on-screen instructions to use the program:

Enter the number of working days in a week.
Enter the number of slots per day.
Menu Options
Add subjects and schedule (Option 1):

Allows you to add subjects and schedule them randomly on the timetable.
Ensures that each subject appears at least once a day.
Subjects are randomly assigned to available slots.
Display timetable (Option 2):

Displays the current timetable in a tabular format.
Change subject slot (Option 3):

Allows you to change the slot of a subject on a specific day.
Enter the day and slot to change and provide the new subject name.
Delete subject (Option 4):

Allows you to delete a subject from a specific slot on a specific day.
Enter the day and slot to delete the subject from.
Exit (Option 5):

Exits the program.
License
This project is licensed under the MIT License - see the LICENSE file for details.

Author
