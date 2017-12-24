A=[31,-13,0,0,0,-10,0,0,0;-13,35,-9,0,-11,0,0,0,0;0,-9,31,-10,0,0,0,0,0;0,0,-10,79,-30,0,0,0,-9;0,0,0,-30,57,-7,0,-5,0;0,0,0,0,-7,47,-30,0,0;0,0,0,0,0,-30,41,0,0;0,0,0,0,-5,0,0,27,-2;0,0,0,-9,0,0,0,-2,29];
b=[-15;27;-23;0;-20;12;-7;7;10];
eps=1e-7;
L=tril(A,-1);
U=triu(A,1);
D=tril(A)-L;
file=fopen("SOR.txt","w");
for w=0.02:0.02:1.98
    S=(D+w*L)\((1-w)*D-w*U);
    f=w*(D+w*L)\b;
    count=0;
    x1=ones(9,1);
    x0=zeros(9,1);
    while(max(abs(x0-x1))>eps)
        x0=x1;
        x1=S*x0+f;
        count=count+1;
    end
    fprintf(file,"w= %f\n\n",w);
    fprintf(file,"iteration times= %f\n\n",count);
    fprintf(file,"%f\n",x1);
end