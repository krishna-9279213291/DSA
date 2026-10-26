class Solution {
private:   
    string below20[20]={"", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen",
        "Nineteen"};

    string tens[10]={"", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string convert(int num){
        if(num==0) return "";
        if(num<20) return below20[num];

        if(num<100){
            return tens[num/10]+ (num%10?" "+convert(num%10):"");
        }

        return below20[num/100]+ " Hundred" + (num%100?" "+ convert(num%100):"");
    }
public:
    string numberToWords(int num) {
        if(num==0) return "Zero";
        string scale[]={"","Thousand","Million","Billion"};
        int i=0;
        string ans;

        while(num>0){
            int chunk=num%1000;

            if(chunk!=0){
                string part=convert(chunk);

                if(scale[i]!="")
                    part+=" "+scale[i];
                
                if(ans=="")
                    ans=part;
                else
                    ans=part+" "+ans;
            }
            num/=1000;
            i++;
        }
        return ans;
    }
};