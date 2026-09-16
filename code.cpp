#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int choice;
    int age;
    float heightcm;
    float heightmeters;
    float weight;
    float targetweight;
    string name;
    string gender;
    float bmi;
    int trainbody;
    char injury;
    string injury1;
    int nutriChoice;

    do {
        
        
        cout<<"      SMART GYM ADVISOR      "<<endl;
        
        cout<<"1. Weight Loss"<<endl;
        cout<<"2. Muscle Gain"<<endl;
        cout<<"3. Strength, Core & Ability Training"<<endl;
        cout<<"4. Streching"<<endl;
        cout<<"5. Protein, Carbohydrate & Calories Foods"<<endl;
        cout<<"6. Exit"<<endl;
        

        do {
            cout<<"Enter Your Goal (1-6): ";
            cin>>choice;
            if(choice < 1 || choice > 6)
                cout<<"Invalid Choice! Enter between 1 and 6.\n";
        } while(choice < 1 || choice > 6);

        switch(choice){

        case 1:
            cout<<"\nYou Selected: Weight Loss\n"<<endl;
            cout<<"Let's Make Your Dream Come True. Let's Go Buddy!\n"<<endl;

            cout<<"Enter Your NAME: ";
            cin.ignore();
            getline(cin, name);
            if(name.empty()){
                cout<<"Invalid Name! Please enter your name."<<endl;
                break;
            }

            do {
                cout<<"Enter Your AGE: ";
                cin>>age;
                if(age < 10 || age > 80)
                    cout<<"Invalid Age! Enter between 10 and 80.\n";
            } while(age < 10 || age > 80);

            if(age < 15){
                cout<<"Your Age Is Not Enough To Go GYM. Do jogging and cycling."<<endl;
                break;
            }
            else if(age > 60){
                cout<<"Consult a Doctor Before Starting any Training."<<endl;
                break;
            }

            do {
                cout<<"Enter Your Gender (M/F): ";
                cin>>gender;
                if(gender != "m" && gender != "M" && gender != "f" && gender != "F")
                    cout<<"Invalid Gender! Enter M or F only.\n";
            } while(gender != "m" && gender != "M" && gender != "f" && gender != "F");

            do {
                cout<<"Enter Your Height In CM (e.g. 170): ";
                cin>>heightcm;
                if(heightcm < 100 || heightcm > 230)
                    cout<<"Invalid Height! Enter between 100 and 230 cm.\n";
            } while(heightcm < 100 || heightcm > 230);

            heightmeters = heightcm / 100.0;

            do {
                cout<<"Enter Your Current Weight (kg): ";
                cin>>weight;
                if(weight < 30 || weight > 250)
                    cout<<"Invalid Weight! Enter between 30 and 250 kg.\n";
            } while(weight < 30 || weight > 250);

            do {
                cout<<"Enter Your Target Weight (kg): ";
                cin>>targetweight;
                if(targetweight < 30 || targetweight > 250)
                    cout<<"Invalid! Enter between 30 and 250 kg.\n";
                else if(targetweight >= weight)
                    cout<<"Target weight must be LESS than current weight for weight loss!\n";
            } while(targetweight >= weight || targetweight < 30 || targetweight > 250);

            cout<<"\n====== YOUR PROFILE IS COMPLETE ======"<<endl;
            bmi = weight / (heightmeters * heightmeters);
            cout<<"Your BMI        : "<<bmi<<endl;

            if(bmi < 18.5){
                cout<<"BMI Status      : Underweight — Weight loss is dangerous! Consult a doctor."<<endl;
                break;
            }
            else if(bmi < 24.9){ cout<<"BMI Status      : Healthy"<<endl; }
            else if(bmi < 29.9){ cout<<"BMI Status      : Overweight"<<endl; }
            else               { cout<<"BMI Status      : Obese"<<endl; }

            {
                float calories, protein;
                if(gender == "m" || gender == "M"){
                    calories = 88.36 + (13.4 * weight) + (4.8 * heightcm) - (5.7 * age);
                } else {
                    calories = 447.6 + (9.2 * weight) + (3.1 * heightcm) - (4.3 * age);
                }
                protein = weight * 1.6;
                float diff  = weight - targetweight;
                float weeks = diff / 0.5;

                cout<<"Daily Calories  : "<<calories - 500<<" kcal/day"<<endl;
                cout<<"Protein Intake  : "<<protein<<" g/day"<<endl;
                cout<<"Estimated Time  : "<<weeks<<" weeks to reach goal"<<endl;
            }

            do {
                cout<<"\nHow Many Days Per Week (3 or 5): ";
                cin>>trainbody;
                if(trainbody != 3 && trainbody != 5)
                    cout<<"Invalid! Enter 3 or 5 only.\n";
            } while(trainbody != 3 && trainbody != 5);

            do {
                cout<<"Do You Have Any Past Injury? (Y/N): ";
                cin>>injury;
                if(injury != 'Y' && injury != 'y' && injury != 'N' && injury != 'n')
                    cout<<"Invalid! Enter Y or N only.\n";
            } while(injury != 'Y' && injury != 'y' && injury != 'N' && injury != 'n');

            if(injury == 'Y' || injury == 'y'){
                cout<<"Where Is Your Injury (Back/Knee/Shoulder/Other): ";
                cin>>injury1;
            }

            if((injury == 'Y' || injury == 'y') && trainbody == 3){
                string days[3] = {"Monday","Wednesday","Friday"};
                cout<<"\n--- 3 Day Weight Loss Plan (With Injury) ---"<<endl;
                string schedule[3] = {
                    "Upper Body Cardio + Core (No Impact)",
                    "Seated Cardio + Stretching",
                    "Light Full Body + Recovery"
                };
                string ex[3][4] = {
                    {"Seated Cycling       - 20 min",
                     "Arm Circles          - 3x15 reps",
                     "Seated Crunches      - 3x15 reps",
                     "Breathing Stretches  - 5 min"},
                    {"Recumbent Bike       - 20 min",
                     "Shoulder Rolls       - 3x15 reps",
                     "Neck Stretches       - 3x30 sec",
                     "Cat-Cow Stretch      - 3x10 reps"},
                    {"Walking slow         - 15 min",
                     "Wall Push-ups        - 3x10 reps",
                     "Standing Side Bends  - 3x15 reps",
                     "Full Body Stretch    - 5 min"}
                };
                for(int i=0;i<3;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
                cout<<"\nInjury Advice: Avoid running, jumping, heavy lifting."<<endl;
            }
            else if((injury == 'N' || injury == 'n') && trainbody == 3){
                string days[3] = {"Monday","Wednesday","Friday"};
                cout<<"\n--- 3 Day Weight Loss Plan (Without Injury) ---"<<endl;
                string schedule[3] = {"Cardio + Core","Full Body Circuit","Cardio + HIIT"};
                string ex[3][4] = {
                    {"Treadmill Running    - 3x20 min",
                     "Jump Rope            - 3x5 min",
                     "Plank                - 3x30 sec",
                     "Bicycle Crunches     - 3x20 reps"},
                    {"Burpees              - 3x10 reps",
                     "Bodyweight Squats    - 3x15 reps",
                     "Push-ups             - 3x12 reps",
                     "Mountain Climbers    - 3x30 sec"},
                    {"Cycling              - 20 min",
                     "High Knees           - 3x30 sec",
                     "Box Jumps            - 3x10 reps",
                     "Jumping Jacks        - 3x30 sec"}
                };
                for(int i=0;i<3;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }
            else if((injury == 'Y' || injury == 'y') && trainbody == 5){
                string days[5] = {"Monday","Tuesday","Wednesday","Thursday","Friday"};
                cout<<"\n--- 5 Day Weight Loss Plan (With Injury) ---"<<endl;
                string schedule[5] = {
                    "Upper Body Light Cardio",
                    "Seated Cardio + Core",
                    "Stretching + Recovery",
                    "Low Impact Cardio",
                    "Full Body Light Movement"
                };
                string ex[5][4] = {
                    {"Seated Cycling       - 20 min","Arm Circles    - 3x15","Wall Push-ups  - 3x10","Shoulder Stretch - 3x30 sec"},
                    {"Recumbent Bike       - 20 min","Seated Crunches- 3x15","Leg Raises     - 3x12","Cat-Cow Stretch  - 3x10"},
                    {"Full Body Stretch    - 10 min","Child Pose     - 3x40 sec","Hip Flexor Stretch - 3x30 sec","Breathing - 5 min"},
                    {"Walking slow         - 20 min","Side Leg Raises- 3x15","Calf Raises    - 3x15","Neck Stretches   - 3x30 sec"},
                    {"Light Cycling        - 15 min","Side Bends     - 3x15","Wall Sit       - 3x20 sec","Full Body Stretch - 5 min"}
                };
                for(int i=0;i<5;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
                cout<<"\nInjury Advice: Low impact only. Consult physiotherapist if pain increases."<<endl;
            }
            else if((injury == 'N' || injury == 'n') && trainbody == 5){
                string days[5] = {"Monday","Tuesday","Wednesday","Thursday","Friday"};
                cout<<"\n--- 5 Day Weight Loss Plan (Without Injury) ---"<<endl;
                string schedule[5] = {
                    "Cardio + Core",
                    "Upper Body + Cardio",
                    "Full Body Circuit",
                    "Lower Body + Cardio",
                    "HIIT + Stretching"
                };
                string ex[5][4] = {
                    {"Treadmill Running    - 3x20 min","Plank          - 3x30 sec","Bicycle Crunches - 3x20","Jump Rope - 3x5 min"},
                    {"Push-ups             - 3x12","Dumbbell Rows  - 3x12","Shoulder Press - 3x12","Cycling   - 15 min"},
                    {"Burpees              - 3x10","Squats         - 3x15","Mountain Climbers - 3x30 sec","Wall Sit  - 3x30 sec"},
                    {"Lunges               - 3x12","Leg Press      - 3x15","Glute Bridges  - 3x15","Treadmill Incline - 20 min"},
                    {"High Knees           - 3x30 sec","Box Jumps   - 3x10","Jumping Jacks  - 3x30 sec","Full Body Stretch - 10 min"}
                };
                for(int i=0;i<5;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }

            cout<<"\nSupplement: No powder needed for weight loss."<<endl;
            cout<<"WARNING: Do NOT use any Steroid. Natural training only."<<endl;
            break;

        case 2:
            cout<<"\nYou Selected: Muscle Gain\n"<<endl;
            cout<<"Let's Make Your Dream Come True. Let's Go Buddy!\n"<<endl;

            cout<<"Enter Your NAME: ";
            cin.ignore();
            getline(cin, name);

            do {
                cout<<"Enter Your AGE: ";
                cin>>age;
                if(age < 10 || age > 80)
                    cout<<"Invalid Age! Enter between 10 and 80.\n";
            } while(age < 10 || age > 80);

            if(age < 15){ cout<<"Too young for gym. Do bodyweight exercises only."<<endl; break; }
            if(age > 60){ cout<<"Consult a Doctor before starting."<<endl; break; }

            do {
                cout<<"Enter Your Gender (M/F): ";
                cin>>gender;
                if(gender!="m"&&gender!="M"&&gender!="f"&&gender!="F")
                    cout<<"Invalid! Enter M or F only.\n";
            } while(gender!="m"&&gender!="M"&&gender!="f"&&gender!="F");

            do {
                cout<<"Enter Your Height In CM: ";
                cin>>heightcm;
                if(heightcm < 100 || heightcm > 230)
                    cout<<"Invalid Height! Enter between 100 and 230.\n";
            } while(heightcm < 100 || heightcm > 230);
            heightmeters = heightcm / 100.0;

            do {
                cout<<"Enter Your Current Weight (kg): ";
                cin>>weight;
                if(weight < 30 || weight > 250)
                    cout<<"Invalid Weight! Enter between 30 and 250.\n";
            } while(weight < 30 || weight > 250);

            do {
                cout<<"Enter Your Target Weight (kg): ";
                cin>>targetweight;
                if(targetweight < 30 || targetweight > 250)
                    cout<<"Invalid! Enter between 30 and 250.\n";
                else if(targetweight <= weight)
                    cout<<"Target weight must be MORE than current weight for muscle gain!\n";
            } while(targetweight <= weight || targetweight < 30);

            {
                bmi = weight / (heightmeters * heightmeters);
                cout<<"\n====== YOUR PROFILE IS COMPLETE ======"<<endl;
                cout<<"Your BMI        : "<<bmi<<endl;
                if(bmi < 18.5)       cout<<"BMI Status      : Underweight"<<endl;
                else if(bmi < 24.9)  cout<<"BMI Status      : Healthy"<<endl;
                else if(bmi < 29.9)  cout<<"BMI Status      : Overweight"<<endl;
                else                 cout<<"BMI Status      : Obese"<<endl;

                float calories;
                if(gender=="m"||gender=="M")
                    calories = 88.36 + (13.4*weight) + (4.8*heightcm) - (5.7*age);
                else
                    calories = 447.6 + (9.2*weight) + (3.1*heightcm) - (4.3*age);

                cout<<"Daily Calories  : "<<calories + 300<<" kcal/day"<<endl;
                cout<<"Protein Intake  : "<<weight * 2.0<<" g/day"<<endl;
            }

            do {
                cout<<"\nHow Many Days Per Week (3 or 5): ";
                cin>>trainbody;
                if(trainbody!=3 && trainbody!=5)
                    cout<<"Invalid! Enter 3 or 5 only.\n";
            } while(trainbody!=3 && trainbody!=5);

            do {
                cout<<"Do You Have Any Past Injury? (Y/N): ";
                cin>>injury;
                if(injury!='Y'&&injury!='y'&&injury!='N'&&injury!='n')
                    cout<<"Invalid! Enter Y or N only.\n";
            } while(injury!='Y'&&injury!='y'&&injury!='N'&&injury!='n');

            if(injury=='Y'||injury=='y'){
                cout<<"Where Is Your Injury: ";
                cin>>injury1;
            }

            if((injury=='Y'||injury=='y') && trainbody==3){
                string days[3]={"Monday","Wednesday","Friday"};
                cout<<"\n--- 3 Day Muscle Gain Plan (With Injury) ---"<<endl;
                string schedule[3]={"Upper Body Light","Back + Biceps Light","Legs Light + Core"};
                string ex[3][4]={
                    {"Cable Chest Fly  - 3x12","DB Lateral Raise - 3x12","Incline DB Press - 3x10","Tricep Pushdown  - 3x12"},
                    {"Seated Cable Row - 3x12","Lat Pulldown     - 3x12","Dumbbell Curl    - 3x12","Face Pulls       - 3x15"},
                    {"Leg Press        - 3x12","Leg Extension    - 3x12","Calf Raises      - 3x15","Plank            - 3x30 sec"}
                };
                for(int i=0;i<3;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }
            else if((injury=='N'||injury=='n') && trainbody==3){
                string days[3]={"Monday","Wednesday","Friday"};
                cout<<"\n--- 3 Day Muscle Gain Plan (Without Injury) ---"<<endl;
                string schedule[3]={"Chest + Triceps","Back + Biceps","Legs + Shoulders"};
                string ex[3][4]={
                    {"Bench Press      - 4x10","Incline DB Press - 3x10","Cable Fly        - 3x12","Tricep Pushdown  - 3x12"},
                    {"Deadlift         - 4x8" ,"Pull-ups         - 3xmax","Seated Cable Row - 3x12","Dumbbell Curl  - 3x12"},
                    {"Squat            - 4x10","Leg Press        - 3x12","Shoulder Press   - 3x10","Lateral Raises - 3x15"}
                };
                for(int i=0;i<3;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }
            else if((injury=='Y'||injury=='y') && trainbody==5){
                string days[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
                cout<<"\n--- 5 Day Muscle Gain Plan (With Injury) ---"<<endl;
                string schedule[5]={"Chest Light","Back + Biceps Light","Rest + Stretch","Legs Light","Shoulders + Core"};
                string ex[5][4]={
                    {"Cable Fly        - 3x12","Incline DB Press - 3x10","Pec Deck         - 3x12","Tricep Pushdown  - 3x12"},
                    {"Lat Pulldown     - 3x12","Seated Cable Row - 3x12","Face Pulls       - 3x15","DB Curl          - 3x12"},
                    {"Full Body Stretch- 10min","Child Pose       - 3x40s","Hip Flexor       - 3x30s","Breathing        - 5 min"},
                    {"Leg Press        - 3x12","Leg Extension    - 3x12","Calf Raises      - 3x15","Leg Curl         - 3x12"},
                    {"DB Lateral Raise - 3x15","Front Raises     - 3x12","Plank            - 3x40s","Cable Crunches   - 3x15"}
                };
                for(int i=0;i<5;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }
            else if((injury=='N'||injury=='n') && trainbody==5){
                string days[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
                cout<<"\n--- 5 Day Muscle Gain Plan (Without Injury) ---"<<endl;
                string schedule[5]={"Chest + Triceps","Back + Biceps","Legs + Core","Shoulders + Arms","Full Body Compound"};
                string ex[5][4]={
                    {"Bench Press      - 4x10","Incline DB Press - 3x10","Cable Fly        - 3x12","Tricep Pushdown  - 3x12"},
                    {"Deadlift         - 4x8" ,"Pull-ups         - 3xmax","Seated Cable Row - 3x12","DB Curl          - 3x12"},
                    {"Squat            - 4x10","Leg Press        - 3x12","Leg Curl         - 3x12","Plank            - 3x40s"},
                    {"Shoulder Press   - 4x10","Lateral Raises   - 3x15","Bicep Curl       - 3x12","Skull Crushers   - 3x12"},
                    {"Bench Press      - 3x8" ,"Squat            - 3x8" ,"Deadlift         - 3x6" ,"Pull-ups         - 3xmax"}
                };
                for(int i=0;i<5;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }

            cout<<"\nSupplement: Whey Protein Powder + Creatine Monohydrate"<<endl;
            cout<<"WARNING: Do NOT use any Steroid. Natural training only."<<endl;
            break;

        case 3:
            cout<<"\nYou Selected: Strength, Core & Ability Training\n"<<endl;
            cout<<"Let's Make Your Dream Come True. Let's Go Buddy!\n"<<endl;

            cout<<"Enter Your NAME: ";
            cin.ignore();
            getline(cin, name);

            do {
                cout<<"Enter Your AGE: ";
                cin>>age;
                if(age < 10 || age > 80)
                    cout<<"Invalid Age! Enter between 10 and 80.\n";
            } while(age < 10 || age > 80);

            if(age < 15){ cout<<"Too young. Do bodyweight exercises only."<<endl; break; }
            if(age > 60){ cout<<"Consult a Doctor before starting."<<endl; break; }

            do {
                cout<<"Enter Your Gender (M/F): ";
                cin>>gender;
                if(gender!="m"&&gender!="M"&&gender!="f"&&gender!="F")
                    cout<<"Invalid! Enter M or F only.\n";
            } while(gender!="m"&&gender!="M"&&gender!="f"&&gender!="F");

            do {
                cout<<"Enter Your Height In CM: ";
                cin>>heightcm;
                if(heightcm < 100 || heightcm > 230)
                    cout<<"Invalid Height! Enter between 100 and 230.\n";
            } while(heightcm < 100 || heightcm > 230);
            heightmeters = heightcm / 100.0;

            do {
                cout<<"Enter Your Current Weight (kg): ";
                cin>>weight;
                if(weight < 30 || weight > 250)
                    cout<<"Invalid Weight! Enter between 30 and 250.\n";
            } while(weight < 30 || weight > 250);

            {
                bmi = weight / (heightmeters * heightmeters);
                cout<<"\n====== YOUR PROFILE IS COMPLETE ======"<<endl;
                cout<<"Your BMI        : "<<bmi<<endl;
                if(bmi < 18.5)       cout<<"BMI Status      : Underweight"<<endl;
                else if(bmi < 24.9)  cout<<"BMI Status      : Healthy"<<endl;
                else if(bmi < 29.9)  cout<<"BMI Status      : Overweight"<<endl;
                else                 cout<<"BMI Status      : Obese"<<endl;

                float calories;
                if(gender=="m"||gender=="M")
                    calories = 88.36 + (13.4*weight) + (4.8*heightcm) - (5.7*age);
                else
                    calories = 447.6 + (9.2*weight) + (3.1*heightcm) - (4.3*age);

                cout<<"Daily Calories  : "<<calories + 200<<" kcal/day"<<endl;
                cout<<"Protein Intake  : "<<weight * 1.8<<" g/day"<<endl;
            }

            do {
                cout<<"\nHow Many Days Per Week (3 or 5): ";
                cin>>trainbody;
                if(trainbody!=3 && trainbody!=5)
                    cout<<"Invalid! Enter 3 or 5 only.\n";
            } while(trainbody!=3 && trainbody!=5);

            do {
                cout<<"Do You Have Any Past Injury? (Y/N): ";
                cin>>injury;
                if(injury!='Y'&&injury!='y'&&injury!='N'&&injury!='n')
                    cout<<"Invalid! Enter Y or N only.\n";
            } while(injury!='Y'&&injury!='y'&&injury!='N'&&injury!='n');

            if(injury=='Y'||injury=='y'){
                cout<<"Where Is Your Injury: ";
                cin>>injury1;
            }

            if((injury=='Y'||injury=='y') && trainbody==3){
                string days[3]={"Monday","Wednesday","Friday"};
                cout<<"\n--- 3 Day Strength Plan (With Injury) ---"<<endl;
                string schedule[3]={"Upper Body Light","Core + Stability","Lower Body Light"};
                string ex[3][4]={
                    {"Cable Chest Press- 3x6","Lat Pulldown     - 3x6","DB Shoulder Press- 3x6","Face Pulls       - 3x12"},
                    {"Plank            - 4x45s","Dead Bug        - 3x10","Bird Dog         - 3x10","Side Plank       - 3x30s"},
                    {"Leg Press        - 3x6","Leg Extension    - 3x10","Calf Raises      - 3x15","Glute Bridge     - 3x12"}
                };
                for(int i=0;i<3;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }
            else if((injury=='N'||injury=='n') && trainbody==3){
                string days[3]={"Monday","Wednesday","Friday"};
                cout<<"\n--- 3 Day Strength Plan (Without Injury) ---"<<endl;
                string schedule[3]={"Squat Focus","Bench Press Focus","Deadlift Focus"};
                string ex[3][4]={
                    {"Barbell Squat    - 5x5","Leg Press        - 3x6","Lunges           - 3x8","Plank            - 3x45s"},
                    {"Bench Press      - 5x5","Incline Press    - 3x6","Shoulder Press   - 3x6","Tricep Dips      - 3x8"},
                    {"Deadlift         - 5x4","Bent Over Row    - 4x6","Pull-ups         - 3xmax","Farmer Walk     - 3x30m"}
                };
                for(int i=0;i<3;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }
            else if((injury=='Y'||injury=='y') && trainbody==5){
                string days[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
                cout<<"\n--- 5 Day Strength Plan (With Injury) ---"<<endl;
                string schedule[5]={"Upper Body Light","Core + Stability","Rest + Stretch","Lower Body Light","Full Body Light"};
                string ex[5][4]={
                    {"Cable Chest Press- 3x6","Lat Pulldown     - 3x6","DB Shoulder Press- 3x6","Face Pulls       - 3x12"},
                    {"Plank            - 4x45s","Dead Bug        - 3x10","Bird Dog         - 3x10","Side Plank       - 3x30s"},
                    {"Full Body Stretch- 10min","Child Pose      - 3x40s","Hip Flexor       - 3x30s","Breathing        - 5min"},
                    {"Leg Press        - 3x6","Leg Extension    - 3x10","Calf Raises      - 3x15","Glute Bridge     - 3x12"},
                    {"Cable Chest Press- 3x5","Lat Pulldown     - 3x5","Leg Press        - 3x5","Plank            - 3x45s"}
                };
                for(int i=0;i<5;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }
            else if((injury=='N'||injury=='n') && trainbody==5){
                string days[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
                cout<<"\n--- 5 Day Strength Plan (Without Injury) ---"<<endl;
                string schedule[5]={"Squat Focus","Upper Body Push","Deadlift Focus","Upper Body Pull","Full Body Compound"};
                string ex[5][4]={
                    {"Barbell Squat    - 5x5","Leg Press        - 3x6","Lunges           - 3x8","Plank            - 3x45s"},
                    {"Bench Press      - 5x5","Incline Press    - 3x6","Shoulder Press   - 3x6","Tricep Dips      - 3x8"},
                    {"Deadlift         - 5x4","Bent Over Row    - 4x5","Farmer Walk      - 3x30m","Core Plank       - 3x45s"},
                    {"Pull-ups         - 4xmax","Seated Cable Row- 4x6","Face Pulls       - 3x12","Bicep Curl       - 3x8"},
                    {"Barbell Squat    - 3x4","Bench Press      - 3x4","Deadlift         - 3x3","Pull-ups         - 3xmax"}
                };
                for(int i=0;i<5;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }

            cout<<"\nSupplement: Whey Protein Powder + Creatine Monohydrate"<<endl;
            cout<<"WARNING: Do NOT use any Steroid. Natural training only."<<endl;
            break;

        case 4:
            cout<<"\nYou Selected: Stretching\n"<<endl;
            cout<<"Let's Make Your Dream Come True. Let's Go Buddy!\n"<<endl;

            cout<<"Enter Your NAME: ";
            cin.ignore();
            getline(cin, name);

            do {
                cout<<"Enter Your AGE: ";
                cin>>age;
                if(age < 10 || age > 80)
                    cout<<"Invalid Age! Enter between 10 and 80.\n";
            } while(age < 10 || age > 80);

            if(age < 15){ cout<<"Too young. Do light stretching at home."<<endl; break; }
            if(age > 60){ cout<<"Consult a Doctor before starting."<<endl; break; }

            do {
                cout<<"How Many Days Per Week (3 or 5): ";
                cin>>trainbody;
                if(trainbody!=3 && trainbody!=5)
                    cout<<"Invalid! Enter 3 or 5 only.\n";
            } while(trainbody!=3 && trainbody!=5);

            do {
                cout<<"Do You Have Any Past Injury? (Y/N): ";
                cin>>injury;
                if(injury!='Y'&&injury!='y'&&injury!='N'&&injury!='n')
                    cout<<"Invalid! Enter Y or N only.\n";
            } while(injury!='Y'&&injury!='y'&&injury!='N'&&injury!='n');

            if(injury=='Y'||injury=='y'){
                cout<<"Where Is Your Injury: ";
                cin>>injury1;
            }

            if((injury=='Y'||injury=='y') && trainbody==3){
                string days[3]={"Monday","Wednesday","Friday"};
                cout<<"\n--- 3 Day Stretching Plan (With Injury) ---"<<endl;
                string schedule[3]={"Upper Body Gentle","Lower Body Gentle","Full Body Recovery"};
                string ex[3][4]={
                    {"Neck Stretch     - Hold 30s x3","Shoulder Cross   - Hold 30s x3","Chest Opener     - Hold 30s x3","Wrist Circles    - 3x15"},
                    {"Seated Hamstring - Hold 30s x3","Hip Flexor       - Hold 30s x3","Calf Stretch     - Hold 30s x3","Ankle Circles    - 3x15"},
                    {"Child Pose       - Hold 40s x3","Cat-Cow Stretch  - 3x10","Breathing        - 5 min","Full Body Relax  - 5 min"}
                };
                for(int i=0;i<3;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }
            else if((injury=='N'||injury=='n') && trainbody==3){
                string days[3]={"Monday","Wednesday","Friday"};
                cout<<"\n--- 3 Day Stretching Plan (Without Injury) ---"<<endl;
                string schedule[3]={"Upper Body Stretch","Lower Body Stretch","Full Body Flexibility"};
                string ex[3][4]={
                    {"Chest Opener     - Hold 30s x3","Shoulder Stretch - Hold 30s x3","Tricep Stretch   - Hold 30s x3","Neck Stretch     - Hold 30s x3"},
                    {"Hamstring Stretch- Hold 40s x3","Hip Flexor       - Hold 30s x3","Quad Stretch     - Hold 30s x3","Calf Stretch     - Hold 30s x3"},
                    {"Child Pose       - Hold 40s x3","Cat-Cow Stretch  - 3x10","Spinal Twist     - Hold 30s x3","Full Body Stretch- 5 min"}
                };
                for(int i=0;i<3;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }
            else if((injury=='Y'||injury=='y') && trainbody==5){
                string days[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
                cout<<"\n--- 5 Day Stretching Plan (With Injury) ---"<<endl;
                string schedule[5]={"Upper Body Gentle","Lower Body Gentle","Rest + Breathing","Full Body Gentle","Recovery Stretch"};
                string ex[5][4]={
                    {"Neck Stretch     - Hold 30s x3","Shoulder Cross   - Hold 30s x3","Chest Opener     - Hold 30s x3","Wrist Circles    - 3x15"},
                    {"Seated Hamstring - Hold 30s x3","Hip Flexor       - Hold 30s x3","Calf Stretch     - Hold 30s x3","Ankle Circles    - 3x15"},
                    {"Breathing        - 10 min","Child Pose       - Hold 40s x3","Supine Twist     - Hold 30s x3","Savasana         - 5 min"},
                    {"Cat-Cow Stretch  - 3x10","Hip Circles      - 3x10","Seated Spinal    - Hold 30s x3","Glute Stretch    - Hold 30s x3"},
                    {"Full Body Stretch- 10 min","Child Pose       - Hold 40s x3","Breathing        - 5 min","Full Body Relax  - 5 min"}
                };
                for(int i=0;i<5;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }
            else if((injury=='N'||injury=='n') && trainbody==5){
                string days[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
                cout<<"\n--- 5 Day Stretching Plan (Without Injury) ---"<<endl;
                string schedule[5]={"Upper Body Stretch","Lower Body Stretch","Core + Back Stretch","Full Body Flexibility","Deep Stretch + Recovery"};
                string ex[5][4]={
                    {"Chest Opener     - Hold 30s x3","Shoulder Stretch - Hold 30s x3","Tricep Stretch   - Hold 30s x3","Neck Stretch     - Hold 30s x3"},
                    {"Hamstring Stretch- Hold 40s x3","Hip Flexor       - Hold 30s x3","Quad Stretch     - Hold 30s x3","Calf Stretch     - Hold 30s x3"},
                    {"Cat-Cow Stretch  - 3x10","Child Pose       - Hold 40s x3","Spinal Twist     - Hold 30s x3","Lower Back       - Hold 30s x3"},
                    {"Full Body Stretch- 10 min","Hip Circles      - 3x10","Glute Stretch    - Hold 30s x3","IT Band Stretch  - Hold 30s x3"},
                    {"Deep Hip Stretch - Hold 40s x3","Pigeon Pose     - Hold 40s x3","Full Body Relax  - 5 min","Breathing        - 5 min"}
                };
                for(int i=0;i<5;i++){
                    cout<<"\n"<<days[i]<<" : "<<schedule[i]<<endl;
                    for(int j=0;j<4;j++) cout<<"   "<<j+1<<". "<<ex[i][j]<<endl;
                }
            }

            cout<<"\nNo Supplement Needed. Stay Hydrated."<<endl;
            cout<<"WARNING: Do NOT use any Steroid."<<endl;
            break;

        case 5:
            cout<<"\nYou Selected: Protein, Carbohydrate & Calories Foods\n"<<endl;
            cout<<"1. Protein Rich Foods"<<endl;
            cout<<"2. Carbohydrate Rich Foods"<<endl;
            cout<<"3. Calories Rich Foods"<<endl;

            do {
                cout<<"Enter Your Choice (1-3): ";
                cin>>nutriChoice;
                if(nutriChoice < 1 || nutriChoice > 3)
                    cout<<"Invalid! Enter 1, 2 or 3 only.\n";
            } while(nutriChoice < 1 || nutriChoice > 3);

            switch(nutriChoice){
            case 1:{
                cout<<"\n--- Top 10 Halal High Protein Foods ---\n"<<endl;
                string foods[10]={
                    "1.  Chicken Breast   - 54.5g protein per 6oz",
                    "2.  Tuna Fish        - 50.8g protein per 6oz",
                    "3.  Beef Steak       - 48.7g protein per 6oz",
                    "4.  Firm Tofu        - 43.5g protein per cup",
                    "5.  Lentils (Daal)   - 17.9g protein per cup",
                    "6.  Low Fat Yogurt   - 14g   protein per cup",
                    "7.  Parmesan Cheese  - 10.2g protein per oz",
                    "8.  Pumpkin Seeds    - 8.5g  protein per oz",
                    "9.  Eggs             - 6.3g  protein per egg",
                    "10. Milk             - 8g    protein per cup"
                };
                for(int i=0;i<10;i++) cout<<foods[i]<<endl;
                cout<<"\nTip: Eat protein after every workout for muscle recovery."<<endl;
                break;
            }
            case 2:{
                cout<<"\n--- Top 10 Halal Healthy Carbohydrate Foods ---\n"<<endl;
                string foods[10]={
                    "1.  Brown Rice        - 45g carbs per cup",
                    "2.  Sweet Potatoes    - 27g carbs per potato",
                    "3.  Oats              - 54g carbs per cup",
                    "4.  Chickpeas (Chanay)- 45g carbs per cup",
                    "5.  Lentils (Daal)    - 40g carbs per cup",
                    "6.  Banana            - 27g carbs per banana",
                    "7.  Whole Wheat Bread - 20g carbs per slice",
                    "8.  Apples            - 25g carbs per apple",
                    "9.  Dates (Khajoor)   - 75g carbs per 100g",
                    "10. Corn              - 41g carbs per cup"
                };
                for(int i=0;i<10;i++) cout<<foods[i]<<endl;
                cout<<"\nAvoid: Sugary drinks, cakes, chips, fast food."<<endl;
                break;
            }
            case 3:{
                cout<<"\n--- Top 10 Halal High Calorie Foods ---\n"<<endl;
                string foods[10]={
                    "1.  Homemade Granola  - 597 kcal per cup",
                    "2.  Chicken Leg       - 475 kcal per leg",
                    "3.  Salmon Fish       - 350 kcal per 6oz",
                    "4.  Firm Tofu         - 363 kcal per cup",
                    "5.  Avocado           - 322 kcal per avocado",
                    "6.  Milk              - 298 kcal per cup",
                    "7.  Chickpeas (Chanay)- 269 kcal per cup",
                    "8.  Sweet Potatoes    - 258 kcal per cup",
                    "9.  Brown Rice        - 248 kcal per cup",
                    "10. Macadamia Nuts    - 204 kcal per oz"
                };
                for(int i=0;i<10;i++) cout<<foods[i]<<endl;
                cout<<"\nTip: Use these for muscle gain and strength goals."<<endl;
                break;
            }
            }
            break;

        case 6:
            cout<<"\nGoodbye! Stay Consistent. Natural Gains Only!"<<endl;
            break;

        default:
            cout<<"Invalid Choice!"<<endl;
            break;
        }

    } while(choice != 6);  

    return 0;
}
