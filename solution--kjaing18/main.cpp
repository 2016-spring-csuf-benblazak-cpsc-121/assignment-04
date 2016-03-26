// Assignment 4
//Katelyn Jaing

#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

void print_vector( const vector<int> & );
void selection_sort( vector<int> & );
vector<int> merge_sort( vector<int> & );
vector<int> merge_sort2( vector<int>, vector<int>);

int main() {
    vector< int > vect;
    int size;
    cout << "How many numbers do you want to input into the vector? ";
    cin >> size;
    
    for( int i = 0; i < size; i++ )
    {
        int num;
        cout << "Enter number into space " << i + 1 << ": ";
        cin >> num;
        vect.push_back( num );
        cout << endl;
    }
    
    //print_vector( vect );
    
    //selection_sort( vect );
    
    print_vector( merge_sort( vect ) );
    
        return 0;
}

//prints out vector
void print_vector( const vector<int> & vect)
{
    for( int i = 0; i < ( int ) vect.size(); i++ )
    {
        cout << vect[i] << " ";
    }
    cout << endl;
}

//selection sort
void selection_sort( vector<int> & vect )
{
    int size = ( int )vect.size();
    int smallIndex, smallNum;
    for( int i = 0; i < size; i++ )
    {
        smallIndex = i;
        smallNum = vect[i];
        for( int j = i + 1; j < size; j++ )
        {
            if( smallNum > vect[j] )
            {
                smallNum = vect[j];
                smallIndex = j;
            }
        }
        vect[smallIndex] = vect[i];
        vect[i] = smallNum;
    }
    
    //prints out vector
    print_vector( vect );
}

//merge sort
vector<int> merge_sort( vector<int> & vect )
{
    vector<int> left;
    vector<int> right;
    vector<int> sorted;
    
    //base case
    //if vector has 1 element, return the vector
    if( vect.size() == 1 )
        return vect;
    else
    {
        //cut vector in half
        int half = ( int ) vect.size() / 2;
        
        //left
        for( int l = 0; l < half; l++ )
        {
            left.push_back( vect[l] );
        }
        
        //right
        for( int r = half; r < vect.size(); r++ )
        {
            right.push_back( vect[r] );
        }
        
        left = merge_sort( left );
        right = merge_sort( right );
        sorted = merge_sort2( left, right );
    }
    return sorted;
}

vector<int> merge_sort2( vector<int> left, vector<int> right )
{
    vector<int> sorted;
    //comparing left and right sides
    while( left.size() > 0 || right.size() > 0 )
    {
        if( left.size() > 0 && right.size() > 0 )
        {
            if( left.front() <= right.front() )
            {
                sorted.push_back( left.front() );
                left.erase( left.begin() );
            }
            else if( left.front() >= right.front() )
            {
                sorted.push_back( right.front() );
                right.erase( right.begin() );
            }
        }
        else if( left.size() > 0 )
        {
            sorted.push_back( left.front() );
            left.erase( left.begin() );
        }
        else
        {
            sorted.push_back( right.front() );
            right.erase( right.begin() );
        }
    }
    
    return sorted;
}
