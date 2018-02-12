#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
//George Franklin + Matt Fretwell
/*Currently is a combat option selection with the use of taking in type from the user
 * the damage and actual operation/selection will come with integreation with Matt's code
 * steps after this are to use database and make each option selection do something
 * 
 */
using namespace std;

class Combat{
    public:
    string response;
    //string response2;
    int playerHealth = 100;
    int monsterMana = 100;
    int playerMana = 100;
    
    Combat(){        
    }    
    string lower_case(string input){//could combine this with the get_line function so it reduces one line in code      
        for (size_t i = 0; input.size() > i; ++i){
            if ((input[i] >= 'A') && (input[i] <= 'Z')){
                input[i] = input[i] - 'A' + 'a';
            }
        }       
    return input;
    }
        
    string get_line(){ 
        getline(cin, response);
        //response2 = lower_case(response1); to reduce code usage 
    return response;
    }
    
    int weapon_attack_player(int weaponAttackStats){
        
    }
    int spells_attack_player(int magicAbility, int magicItem){
        int magicDamagePlayer = magicAbility * magicItem;
        
    }
    
    int block_player(int defensePlayer)
    
    int meleeAttackM(int attackStr, int itemAttackStr){
    int attackDamageM = attackStr * itemAttackStr;
    }
    
    int magicAttackM(int MagAbil, int itemMagAbil){
        int magicDamageM = MagAbil * itemMagAbil;
        monsterMana - 5;
            
    }
    
    /*int damageTaken(int mAttack){
    int health = health - mAttack;   
        if(health >= 0){
            int v=0;
            //can't do this, im dumb.
        }
    }*/
   
    int blockM(int defM,int itemDefM, int mAttack){
        int block = defM * itemDefM;
        int health = health - (health - mAttack) + block;
    }
    
    //function which stops combat when the monsters health is zero/displays its health as well 


};

class Monster : virtual public Combat{
    public:
    int monster_battlecry(string cry){
        cout << cry << endl;
    }
};

class Goblin : public Monster{
    public:

    int health = rand()%(8-5+1)+5;
    int attackStr = rand()%(8-5+1)+5;
    int magAbil = rand()%(3-1+1)+1;
    int mana = 10;
    int def = rand()%(6-2+1)+2;
        
};

class Wolf : public Monster{
    public:
    
    int health = rand()%(30-10+1)+10;
    int attackStr = rand()%(14-1+1)+1;
    int magAbil = rand()%(10-0+1)+0;
    int mana = 10;
    int def = rand()%(10-3+1)+3;
    
};

class Ugandan_Knuckles : public Monster{
    public:
    

    int health = rand()%(30-10+1)+10;
    int attackStr = rand()%(14-1+1)+1;
    int magAbil = rand()%(10-0+1)+0;
    int mana = 10;
    int def = rand()%(10-3+1)+3;    
    string const uCryOne = "We fight for da qween!";
    string const uCryTwo = "We know de wae.";
    
    int time_to_cry(){
        monster_battlecry(uCryOne);
        monster_battlecry(uCryTwo);
    }
};

class Rabbit : public Monster{
    public:
    
    int health = rand()%(30-10+1)+10;
    int attackStr = rand()%(14-1+1)+1;
    int magAbil = rand()%(10-0+1)+0;
    int mana = 10;
    int def = rand()%(10-3+1)+3;
    
};

class Dragon : public Monster{
    public:

    int health = rand()%(200-150+1)+150;
    int attackStr = rand()%(500-10+1)+10;
    int magAbil = rand()%(200-20+1)+20;
    int mana = 70;
    int def = rand()%(400-100+1)+100;
    
};

class Attack : virtual public Combat{ //use of virtual to stop Diamond Death within classes = https://stackoverflow.com/questions/137282/how-can-i-avoid-the-diamond-of-death-when-using-multiple-inheritance
    public:
    string attackResponse;
    string attackResponseOne;
    string const weaponOne = "dagger"; //database reference just for the name and when they choose the weapon we can call for the rest of the information about it 
    string const weaponTwo = "bow"; 
    string const weaponThree = "sword";
    
    Attack(){        
    }
    
    int attack_response(){
        cout << "These are the weapons you can use: " << endl; 
        cout << "-    Deal damage with a " << weaponOne << endl; //could make each option selection random
        cout << "-    Destroy enemy whilst weilding a " << weaponTwo << endl;
        cout << "-    Put them 6 feet under with your " << weaponThree << endl; //possible code duplication 
        cout << "What weapon would you like to use?" << endl;
        attackResponseOne = get_line();
        attackResponse = lower_case(attackResponseOne);
        attack_choice();
    }
    int attack_choice(){ 
        size_t weaponOptionOne = attackResponse.find(weaponOne);
        if (weaponOptionOne!=string::npos){
            cout << "Weapon 1 works" << endl;
            /*
            return something to the main class to deal damage 
            section would call the database for the specific stats of each of the weapons 
            each section needs to intake the weapon stat(s) and implament that into an action so it would look like, not sure what kinds of stats it would need
            int acttack_choice(weaponDamage)
            could have a weapon durability which after use we can update the database with 
            this adds an element of choice to your weapon selection during a fight 
            need to have a function in combat which combines the stats of the monsters and the this function of the weapon damage */
        }
        size_t weaponOptionTwo = attackResponse.find(weaponTwo);
        if (weaponOptionTwo!=string::npos){
            cout << "Weapon 2 works" << endl;
        }
        size_t weaponOptionThree = attackResponse.find(weaponThree);
        if (weaponOptionThree!=string::npos){
            cout << "Weapon 3 works" << endl;
        }
    }
};

class Spells : virtual public Combat{
    public:
    string spellResponse;
    string spellResponseOne;
    string const spellOne = "decay";//database reference
    string const spellTwo = "potent slap";
    string const spellThree = "loud noise";
    
    Spells(){ //supposedly to initialise the use of the class 
        
    }
    
    int spell_response(){
        cout << "These are the spells you can use: " << endl;  
        cout << "-    Cast " << spellOne << endl;  
        cout << "-    Cast " << spellTwo << endl; 
        cout << "-    Cast " << spellThree << endl; //possible code duplication
        cout << "What spell would you like to use?" << endl;
        spellResponseOne = get_line();
        spellResponse = lower_case(spellResponseOne);
        spell_choice(spellResponse);
    }
    
    int spell_choice(string spellResponse){
        size_t spellAttackOne = spellResponse.find(spellOne);        
        if (spellAttackOne!=string::npos){
            cout << "Spell one works" << endl;
        }
        size_t spellAttackTwo = spellResponse.find(spellTwo);
        if (spellAttackTwo!=string::npos){
            cout << "Spell two works" << endl;
        }
        size_t spellAttackThree = spellResponse.find(spellThree);
        if (spellAttackThree!=string::npos){
            cout << "Spell three works" << endl;
        }
    }
    
};

class Defense : virtual public Combat{
    public:
    string defenseResponse;
    string defenseResponseOne;
    string const defenseOne = "heal";//database reference for each 
    string const defenseTwo = "block";
    string const defenseThree = "potion";
    
    Defense(){
        
    }
    
    int defense_response(){
        cout << "These are the defenses you can use: " << endl; 
        cout << "-    Use ability " << defenseOne << endl; //possible code duplication
        cout << "-    Use ability " << defenseTwo << endl; 
        cout << "-    Use ability " << defenseThree << endl;  
        cout << "What defense would you like to do?" << endl;
        defenseResponseOne = get_line();
        defenseResponse = lower_case(defenseResponseOne);
        defense_choice(defenseResponse);
    }
    int defense_choice(string defenseResponse){    
    size_t defenseOptionOne = defenseResponse.find(defenseOne);
        if (defenseOptionOne != string::npos){
            cout << "Option 1  " << endl;
        }
    size_t defenseOptionTwo = defenseResponse.find(defenseTwo);
        if (defenseOptionTwo!=string::npos){
            cout << "Option 2 works" << endl;
        }
    size_t defenseOptionThree = defenseResponse.find(defenseThree);
        if (defenseOptionThree!=string::npos){
            cout << "Option 3 works" << endl;
        }
    }
};

class User_Response : public Defense, public Attack, public Spells{
    public:    
    string initialResponse;
    string initialResponseOne;
    string responseError;
    string responseErrorOne;
    int nextA;
    int nextD;
    int nextS;
    string const attackSearch = "attack"; 
    string const spellSearch = "spells";
    string const defenseSearch = "defense";
    
    User_Response(){
        
    }
    
    string initial_response(){
        cout << "You can either: " << endl;
        cout << "-    Attack the monster." << endl; //could make these messages random 
        cout << "-    Use a defense ability." << endl;
        cout << "-    Cast spells on the enemy." << endl;
        cout << "What would you like to do?" << endl;
        initialResponseOne = get_line();
        initialResponse = lower_case(initialResponseOne); 
        next_step(initialResponse);
    return initialResponse;
    }
    
    int initial_response_error(){
        cout << "Please enter either, attack, defense or spells" << endl;
        responseErrorOne = get_line();
        responseError = lower_case(responseErrorOne);
        next_step(responseError);
    }
    
        int next_step(string next){
        nextA = next.find(attackSearch);
        nextD = next.find(defenseSearch);
        nextS = next.find(spellSearch); //instead of using find could do a string search algorithm
        //cout << nextA;
        //cout << nextD;
        //cout << nextS;
        
        if (nextA != -1){ //says the index no. if the word is found but if not then it produces a -1 
            Attack NextStep; //Test file proves this 
            NextStep.attack_response();
        }
        else if(nextD != -1){
            Defense NextStep;
            NextStep.defense_response();
        }
        else if(nextS != -1){
            Spells NextStep;
            NextStep.spell_response();
        }
        else{
            initial_response_error();
        }
    }
    
};

int main(){
    srand(time(NULL));
    User_Response testing;
    testing.initial_response();
    return 0;
}
