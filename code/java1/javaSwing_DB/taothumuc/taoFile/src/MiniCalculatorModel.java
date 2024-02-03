public class MiniCalculatorModel {
    private double firstValue;
    private double secondValue;
    private double answer;

    public MiniCalculatorModel(){

    }
    public double getfirst(){
        return firstValue;
    }
    public void setfirst(double firstValue){
        return this.firstValue=firstValue;
    }
    public double getsecond(){
        return secondValue;
    }
    public void setsecond(double secondValue){
        return this.secondValue=secondValue;
    }
    public double getanswer(){
        return answer;
    }
    public void setanswer(double answer){
        return this.answer=answer;
    }
    
    public void cong(){
        this.answer=this.firstValue+this.secondValue;
    }

    public void tru(){
        this.answer=this.firstValue-this.secondValue;
    }

    public void nhan(){
        this.answer=this.firstValue*this.secondValue;
    }

    public void chia(){
        this.answer=this.firstValue/this.secondValue;
    }

    public void pow(){
        this.answer=Math.pow(this.firstValue,this.secondValue);
    }
}

