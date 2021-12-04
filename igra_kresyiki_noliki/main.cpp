#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct Cell {
    string name;
    char value;
};

map<int, vector<Cell>>table_(map<string, Cell>cells) {
    map<int, vector<Cell>>table;
table[0] = { cells.at("a1"), cells.at("a2"),cells.at("a3") };
table[1] = { cells.at("b1"),cells.at("b2"),cells.at("b3") };
table[2] = { cells.at("c1"),cells.at("c2"),cells.at("c3") };
return table;
}

map<int, vector<Cell>>Win_(map<string, Cell>cells)
{
    map<int, vector<Cell>>Win;
    Win[0] = { cells.at("a1"), cells.at("a2"),cells.at("a3") };
    Win[1] = { cells.at("b1"),cells.at("b2"),cells.at("b3") };
    Win[2] = { cells.at("c1"),cells.at("c2"),cells.at("c3") };
    Win[3] = { cells.at("a1"), cells.at("b1"),cells.at("c1") };
    Win[4] = { cells.at("a2"), cells.at("b2"),cells.at("c2") };
    Win[5] = { cells.at("a3"), cells.at("b3"),cells.at("c3") };
    Win[6] = { cells.at("a1"), cells.at("b2"),cells.at("c3") };
    Win[7] = { cells.at("a3"), cells.at("b2"),cells.at("c1") };
    return Win;
}

void print_table(map<string, Cell>cells)
{

    map<int, vector<Cell>>  table = table_(cells);
    map<int, vector<Cell>> Win = Win_(cells);

    cout << "   "s << 1 << " "s << " "s << 2 << " "s << " "s << 3 << " "s << endl;
 
    for (auto c : table) {
        bool first_v = true;
        for (Cell c : table[c.first]) {
            if (first_v) { cout << c.name.substr(0, 1) << " "s; }
            cout << "["s << c.value << "]"s;
            first_v = false;
        } cout << endl;
    }
}

map<int, string>cell_rnd_(map<string, Cell>cells)
{
    map<int, string>cell_4_rnd;
    int i = 0;
    for (auto x : cells) 
    {
        cell_4_rnd[i] = x.second.name; ++i;    
    }
    return cell_4_rnd;
}

string you_move()
{
    cout << "enter your move in the format \"cell with number\""s << endl;
    cout << "(a1, a2, a3, b1, b2, b3, c1, c2, c3):"s << endl;
    string first_move;
    cin >> first_move;
    return first_move;
}
map<string, Cell> Angle(map<string, Cell>cells)
{
    srand(time(NULL));
    cout << "wait..." << endl;
    if((cells[cell_rnd_(cells)[0]].value == '-')
        || (cells[cell_rnd_(cells)[2]].value == '-')
        || (cells[cell_rnd_(cells)[6]].value == '-')
        || (cells[cell_rnd_(cells)[8]].value == '-')
        ){ 
m02:
    int rnd; rnd = rand() % 9;
    if ((rnd == 0) || (rnd == 2) || (rnd == 6) || (rnd == 8))
    {
        if (cells[cell_rnd_(cells)[rnd]].value == '-') { cells[cell_rnd_(cells)[rnd]].value = '0'; }
        else { goto m02; }
    }
    else { goto m02; }
    }
    else
    {
    m03:
        int rnd; rnd = rand() % 9;
        if (cells[cell_rnd_(cells)[rnd]].value == '-') { cells[cell_rnd_(cells)[rnd]].value = '0'; }
        else { goto m03; }
    }
    return cells;
}

bool chek( map<string, Cell>cells) {
    map<int, vector<Cell>> Win = Win_(cells);
    bool ex=false;
    {  //проверка на ничью
      bool  break0 = false;
        int countX = 0; int count0 = 0;
        for (auto v : Win)
        {
            bool if_x = false; bool if_0 = false;
            for (auto vf : v.second)
            {
                if (vf.value == 'X') { if_x = true; }
                if (vf.value == '0') { if_0 = true; }
            }
            if (if_x) { ++countX; } if (if_0) {
                ++count0;
            }
        }
        if (countX >= 8 && count0 >= 8) {
            cout << "drawn game" << endl; ex=true;
        }
    }
    {
    //проверка на победу
    bool   break0 = false;
    for (auto v : Win)
    {
        int count = 0;
        for (auto vf : v.second)
        {
            if (vf.value == 'X') { ++count; }
            if (count == 3) {
                cout << "YOU WIN!" << endl; ex = true;
                break0 = true; break;
            }
        }if (break0) { break; }

    }
    
    }
    {  //проверка на поражение
        bool   break0 = false;
        for (auto v : Win)
        {
            int count = 0;
            for (auto vf : v.second)
            {
                if (vf.value == '0') { ++count; }
                if (count == 3) {
                    cout << "You  lost!" << endl; ex = true;
                    break0 = true; break;
                }
            }if (break0) { break; }

        }
    }
    return ex;
}

int main() 
{
    init:
    cout << "* player 'X', machine '0'" << endl;
    
    string first_move;
    map<string, Cell>cells;// a1, a2, a3, b1, b2, b3, c1, c2, c3;
    cells["a1"].name = "a1", cells["a1"].value = '-';
    cells["a2"].name = "a2", cells["a2"].value = '-';
    cells["a3"].name = "a3", cells["a3"].value = '-';
    cells["b1"].name = "b1", cells["b1"].value = '-';
    cells["b2"].name = "b2", cells["b2"].value = '-';
    cells["b3"].name = "b3", cells["b3"].value = '-';
    cells["c1"].name = "c1", cells["c1"].value = '-';
    cells["c2"].name = "c2", cells["c2"].value = '-';
    cells["c3"].name = "c3", cells["c3"].value = '-';
    map<int, string>cell_4_rnd = cell_rnd_(cells);
    
    print_table(cells);
    
    cout << "choosing the first move"s << endl;
    cout << "0-machine, 1-human:"s << endl;
    int choosing;
    cin >> choosing;
    if (choosing == 1)
    {
          back01:
         first_move = you_move();
        if (cells[first_move].value == '-') { cells[first_move].value = 'X'; }else{goto back01;}
        print_table(cells);
             
        if (cells["b2"].value != 'X') { cells["b2"].value = '0';    
        print_table(cells);
        }
        else 
        {
            cells = Angle(cells);
            print_table(cells);
        }
    player:
        int wh = 0;
        while (wh < 10) {
        back02:
            first_move = you_move();
            if (cells[first_move].value == '-') { cells[first_move].value = 'X'; }
            else { goto back02; }
            print_table(cells);
         if (chek( cells)) { goto ex; }
       
         
         bool break0 = false;  bool break1 = false;
         for (auto v : Win_(cells))
         {
             int count = 0;
             for (auto vf : v.second)
             {
                 if (vf.value == '0') { ++count; }
                 if (count == 2) {
                     for (auto vf : v.second)
                     {
                         if (vf.value == '-') { cells[vf.name].value = '0'; break0 = true; break; }
                     }
                 }
                 if (count == 1) { break1 = true; }
             }if (break0) { break; }

         }
         if (!break0) {
             for (auto v : Win_(cells))
             {
                 int count = 0;
                 for (auto vf : v.second)
                 {
                     if (vf.value == 'X') { ++count; }
                     if (count == 2) {
                         for (auto vf : v.second)
                         {
                             if (vf.value == '-') { cells[vf.name].value = '0'; break0 = true; break; }
                         }
                     }
                     if (count == 1) { break1 = true; }
                 }if (break0) { break; }
             }
                 if ((!break0) && (break1))
                 {
                     for (auto v : Win_(cells))
                     {
                         int count = 0;
                         for (auto vf : v.second)
                         {
                             if (vf.value == '-') { ++count; }
                             if (count == 2) {
                                 for (auto vf : v.second)
                                 {
                                      cells = Angle(cells);
                                      break0 = true; break; 
                                 }
                             }if (break0) { break; }

                         }if (break0) { break; }

                     }
                 }
             
         }
         print_table(cells);
        if(chek(cells)){ goto ex; }      

        ++wh;
        }

    }if (choosing == 0)
    {
        if (cells["b2"].value != 'X') {
            cells["b2"].value = '0';
            print_table(cells);
        back03:
            first_move = you_move();
            if (cells[first_move].value == '-') { cells[first_move].value = 'X'; }
            else { goto back03; }
            print_table(cells);
            cells = Angle(cells);
            print_table(cells);


            goto player;
        }
    }

ex:
    print_table(cells);
    string continue_;
    cout << "start the game again?"s << " y/n:";
        cin >> continue_;
        if ((continue_ == "y") || (continue_ == "Y")) { goto init; }
	return 0;

}