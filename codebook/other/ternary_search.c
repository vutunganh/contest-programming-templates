function ternarySearch(f, left, right, absolutePrecision) 
//left and right are the current bounds; the maximum is between them 
        if (right-left < absolutePrecision) 
        return (left+right)/2     leftThird := (left*2+right)/3     rightThird := (left+right*2)/3 
        if (f(leftThird) < f(rightThird)) 
                return ternarySearch(f, leftThird, right, absolutePrecision) 
        else 
                return ternarySearch(f, left, rightThird, absolutePrecision) 
end