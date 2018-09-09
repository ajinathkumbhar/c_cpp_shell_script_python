#include <iostream>
#include <iomanip>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

#define DEF_SIZE    100
#define LOG(msg)    cout << __func__  \
                    << ": " << __LINE__ << ": " \
                    << msg << '\n'
#define TRUE        1
#define FALSE       0
using namespace std;

class SpStack {
    private:
        int size;
        int top;
        int min, max;
        int stack[DEF_SIZE];
    public:
        SpStack();
        SpStack(int);
        ~SpStack();
        void push(int);
        int pop(void);
        int isEmpty(void);
        int isFull(void);
        int getSize(void) {
            return this->size;
        }
        int getTopIndex(void);
        void setMinMax(int element);
        int getMin(void){
            return min;
        }
        int getMax(void) {
            return max;
        }
};

SpStack::SpStack() {
    LOG("constructed called");
}

// Paramerterised constructor to set size and
// default values
SpStack::SpStack(int size) {
    if ( size > DEF_SIZE) {
        LOG("Size excceds, setting to default size");
        this->size = DEF_SIZE;
    }
    LOG("paramertized constructed called");
    this->size = size;
    top = -1;
    min = 0;
    max = 0;
}

// Deconstructor
SpStack::~SpStack(){
    LOG("deconstructed called");
}

// Push element into stack
void SpStack::push(int element) {
    if (isFull()) {
        LOG("Stack full ...");
        return;
    }
    setMinMax(element);
    top++;
    stack[top] = element;
}

// Pop element from stack
int SpStack::pop() {
    if (isEmpty()) {
        LOG("Oops Empty stack ");
        return -1;
    }
    int element = stack[top];
    top--;
    return element;
}

// Stack empty conditions
int SpStack::isEmpty() {
    if ( top < 0 )
        return TRUE;
    return FALSE;
}

// Stack full condition
int SpStack::isFull() {
    if ( top >= size - 1 )
        return TRUE;
    return FALSE;
}

// Compare new element with previous min and max before
// intserting in to stack
void SpStack::setMinMax(int element) {
    if (isEmpty()) {
        min = element;
        max = element;
        return;
    }
    int topelement = stack[top];
    if (element > topelement && element > max)
        max = element;
    if (element < topelement && element < min)
        min = element;
}

// Get top index for debug
int SpStack::getTopIndex(void) {
    return this->top + 1;
}

int main(int argc, char * argv[]) {
    // set time as feed for random funtion
    srand(time(0));

    // Create stack of size 15
    SpStack st(10);

    // Fill stack with random number
    int size = st.getSize();
    for(int i = 0; i < size ; i++) {
        // get random element of size CHAR_MAX
        st.push(rand() % CHAR_MAX);
    }

    // print min and max element from stack with (O)1 complexity
    cout << "--------------------------" << '\n';
    cout << " size: " << size
         << " min: " << st.getMin()
         << " Max: " << st.getMax() << '\n';
    cout << "--------------------------" << '\n';

    // pop all element from stack
    for( int i = 0; ! st.isEmpty() ; i++)
        cout << "top index : " << st.getTopIndex() << " element : " << st.pop() << '\n';

    return 0;
}
