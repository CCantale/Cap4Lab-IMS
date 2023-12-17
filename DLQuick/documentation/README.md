Version 1.2.0
# Getting Started
Application's download and setup.

## Download
- Go to https://github.com/CCantale/DLQuick and click on the green button named <code><> Code</code>.
 
<img src="https://github.com/CCantale/DLQuick/assets/95633668/0e2e939f-b87d-4c21-b129-4ed5bf9482c1" width=30% height=30%>

- Then select the <code>Download ZIP</code> option, at the bottom of the menu.
 
<img src="https://github.com/CCantale/DLQuick/assets/95633668/3a9d84f9-73e3-4e5f-ada9-d32667a2f39e" width=40% height=40%>

- Unzip the downloaded folder, rename it if you like, and open it. The content should be the following.

![image](https://github.com/CCantale/DLQuick/assets/95633668/73afe6d2-cd72-4d71-8b04-c610114a02a0)

## Setup

- The actual application is in the <code>DLQuick</code> folder, named <code>DLQuick.exe</code>, together with the <code>DLQcontent.txt</code> and <code>incidents.txt</code> files, which are vital for the app to function correctly.
- The <code>documentation</code> folder contains the <code>README.md</code> file whose content you are reading right now. You can delete it, since it's probably more readable in here, but nonetheless it has the advantage of being accessible offline.
- The <code>.gitignore</code> file and the <code>srcs</code> folder are useless if you don't plan to edit the app's source code and contribute to the project. You can delete them as well.
- You can then move the remaining 3 files to anywhere in your computer, as long as you keep them in the same folder. If one of the ".txt" files somehow gets lost, you can just careate a new one, as long as the name stays exactly the same. Notice that Windows won't show the ".txt" ending, even if it is there. If you can see it, it means that your file's name probably ends with ".txt.txt".

![image](https://github.com/CCantale/DLQuick/assets/95633668/99db2918-b036-4c0e-a6de-fff4b8d750a2)

- At each run, the application will edit a file called <code>log.txt</code> in a folder called <code>Logbook</code>. Both folder and file will be created when absent and overwritten every time. You won't ever need to access the <code>Logbook</code> folder, since the logs are more readable when accessed via the application itself, using the Logs feature.

# Basics
How to retrieve data from DLQs and use the application's features to analyse it.
## Get DLQcontent
- Go to Anypoint's [MQ section](https://anypoint.mulesoft.com/mq/organizations/925519b8-dc8b-4891-b731-c54b94885361/environments/9f80688d-0639-45c0-89d6-b121536233ca/destinations/eu-west-1/list/), find the DLQ you want to work on and open its content.
- Then select the entire content by dragging your mouse across it. It's often useful to zoom the page out to perform this action.
<img src="https://github.com/CCantale/DLQuick/assets/95633668/09573814-9fea-4a45-953f-f76cbfede8ac" width=80% height=80%>

- Copy the selection and paste it in <code>DLQcontent.txt</code>, then save. You can close this file now.

<img src="https://github.com/CCantale/DLQuick/assets/95633668/5a6349f0-d6b4-4e36-80a5-6d752c267e4c" width=70% height=70%>

## Use features
Double-click on <code>DLQuick.exe</code>. You'll be prompted with the main menu.

<img src="https://github.com/CCantale/DLQuick/assets/95633668/7079e3ce-24cf-40c2-8a3c-9c551bfda874" width=50% height=50%>

With the exeption of <code>logs</code>, all operations will output their result to a file called <code>result.txt</code>, which you don't need to create, since the application itself will create it in case it is not there. If the file is already there, it will be overwritten. Therefore, if you wish to keep a result for later, you must save it elswhere, before DLQuick's next run.
# Info
After pressing <code>i</code> in the menu, inside <code>result.txt</code> you'll find a list of all the orders in the DLQ, showing each order's ID, EC0 reference and the same reference in its 10 characters short form.
# References
Selected by typing <code>r</code> in the menu. This option will output a list of the references in their complete form.
# Short References
This one corresponds to the letter <code>s</code> and will of course get you the references in their short form. Sometimes the complete form is already 10 characters long. In this case, the complete and short outputs will coincide.
# Doubles
The letter <code>d</code> activates a feature that outputs all orders that appear more than once in the DLQ.
# Filter
Probably the most interesting option, Filter, selected by typing the letter <code>f</code> in the menu, needs the other .txt file that comes with the application: <code>incidents.txt</code>. For this reason, before you call the Filter option, you need to go get all the EC0 references there is an open ticket for related to this queue, in **short** form, and paste them in <code>incidents.txt</code>. They can be preceded or followed by any number of spaces or tabs, but they cannot be on the same line. Here's a couple of examples:
- Wrong: the second and third reference will be considered as one by the application and therefore be invalid for the analysis.

<img src="https://github.com/CCantale/DLQuick/assets/95633668/e70c1c36-30f9-4ef1-9f4d-4e1338f8fcb5" width=40% height=40%>

- Right: all references are on different lines.

<img src="https://github.com/CCantale/DLQuick/assets/95633668/cc2d297b-a309-4eaf-b891-795c927863d9" width=40% height=40%>

Finally, you can launch DLQuick and select the Filter option. It will output a comparison of the data in <code>DLQcontent.txt</code> and <code>incidents.txt</code>. The analysis begins with a list of references that are in the DLQ but **not** in the open incidents. It then shows the double references in the DLQ, if any, and ends by showing the two lists of references extracted from the two .txt files.
# Logs
This option is accessible by typing <code>l</code> in the menu and displays all the logs from the application's last run. Success logs are displayed in green, warnings are in yellow and errors in red. Logs are overwritten at every run, so, as for <code>result.txt</code>, in case you wish to keep the logs to a particular run, you'll need to save the contents of <code>Logbook\log.txt</code> elsewhere.
# Tips and Tricks
- The application won't run if there's an instance of it already open.
- If you wish to compare two DLQs, just use the Short References feature on the first one and then copy-paste the references from <code>result.txt</code> to <code>incidents.txt</code>. Then put the content of the second DLQ in <code>DLQcontent.txt</code> and use the Filter feature.
# Contacts
In case of any issues, you can contact the author at claudio.cantale93@gmail.com
