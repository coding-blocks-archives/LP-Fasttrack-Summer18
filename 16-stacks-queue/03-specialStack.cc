class SpecialStack{};
int main(){
    SpecialStack stk;

    stk.push(2);
    stk.push(1);
    stk.getMin();
    stk.push(-6);
    stk.getMin();
    stk.pop();
    stk.pop();
    stk.pop();
}