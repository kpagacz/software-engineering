for m=2:10 n=m-1;a=-1;b=1;step1=(b-a)/n;x=a:step1:b;y=1./(1+100.*x.*x);step2=(b-a)/100;xt=a:step2:b;wn=polyfit(x,y,n);ywn=polyval(wn,xt);err=abs(ywn-1./(1+100.*xt.*xt));degr(m)=m;error(m)=max(err);bar(degr,error); end