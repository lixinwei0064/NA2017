clear();
A=[3,2,5,4,6;2,1,3,-7,8;5,3,2,5,-4;4,-7,5,1,3;6,8,-4,3,8];
size=size(A,1);
Qs=eye(size);%Saves the product of Q matrices
for count=1:20
    Q=eye(size);
    p=1;q=1;emax=0;%Find the biggest element
    for i=1:size
        for j=1:size
            if abs(A(i,j))>emax && i~=j
                p=i;
                q=j;
                emax=abs(A(i,j));
            end
        end
    end
    if abs(A(q,q)-A(p,p))<1e-6
        c=1/sqrt(2);
        d=c;
    else
        s=(A(q,q)-A(p,p))/2/A(p,q);
        sol=[-s-sqrt(s*s+1),-s+sqrt(s*s+1)];
        [val,ind]=min(abs(sol));
        t=sol(ind);
        c=1/sqrt(1+t*t);
        d=t*c;
    end
    Q(p,p)=c;Q(p,q)=d;Q(q,p)=-d;Q(q,q)=c;
    A=Q.'*A*Q;
    Qs=Qs*Q;
end
for i=1:size
    fprintf("r%d=%f,    v%d(%f, %f, %f, %f, %f)\n",i,A(i,i),i,Qs(1,i),Qs(2,i),Qs(3,i),Qs(4,i),Qs(5,i));
end