#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
struct poi{
	double x,y;
};
struct kk{
	poi  a,b;
}lin1,lin2;
int n;
double area;
double xmul(poi a,poi b,poi x){return ((a.x-x.x)*(b.y-x.y)-(a.y-x.y)*(b.x-x.x));}
poi qjd(poi x1,poi y1,poi x2,poi y2){
	poi ax;
	if (fabs(x1.x-y1.x)<eps){
		if (fabs(x2.x-y2.x)<eps){
			ax.x=0;ax.y=0;
			return ax;
		}else{
			double K=(y2.y-x2.y)/(y2.x-x2.x);
		    double B=y2.y-K*y2.x;
		    ax.x=x1.x;
	    	ax.y=K*ax.x+B;
		}
	}else{
		if (fabs(x2.x-y2.x)<eps){
			double K=(y1.y-x1.y)/(y1.x-x1.x);
		    double B=y1.y-K*y1.x;
		    ax.x=x2.x;
		    ax.y=K*ax.x+B;
		}else{
			double K1=(y1.y-x1.y)/(y1.x-x1.x);
		    double B1=y1.y-K1*y1.x;
			double K2=(y2.y-x2.y)/(y2.x-x2.x);
		    double B2=y2.y-K2*y2.x;
			ax.x=(B2-B1)/(K1-K2);
			ax.y=ax.x*K1+B1;
		}
	}
	return ax;
}
int main(){
	freopen("poj2826.in","r",stdin);
	freopen("poj2826.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lf%lf%lf%lf",&lin1.a.x,&lin1.a.y,&lin1.b.x,&lin1.b.y);
		if (lin1.a.y<lin1.b.y)std::swap(lin1.a,lin1.b);
		scanf("%lf%lf%lf%lf",&lin2.a.x,&lin2.a.y,&lin2.b.x,&lin2.b.y);
		if (lin2.a.y<lin2.b.y)std::swap(lin2.a,lin2.b);
		if (xmul(lin1.a,lin1.b,lin2.a)*xmul(lin1.a,lin1.b,lin2.b)<eps){
			poi p=qjd(lin1.a,lin1.b,lin2.a,lin2.b);
			if (fabs(lin1.a.y-lin1.b.y)<eps||fabs(lin2.a.y-lin2.b.y)<eps)area=eps;
			else 
				if (fabs(lin1.a.x-lin1.b.x)>eps&&fabs(lin2.a.x-lin2.b.x )>eps){
				double K1=(lin1.b.y-lin1.a.y)/(lin1.b.x-lin1.a.x);
				double K2=(lin2.b.y-lin2.a.y)/(lin2.b.x-lin2.a.x);
				if (K1*K2>eps){
					double delta=K1-K2;
					if (delta > eps && K2 > eps && (lin2.a.x-lin1.a.x)*(lin2.a.x-p.x) <= eps  
                        || delta < eps && K2 > eps && (lin1.a.x-lin2.a.x)*(lin1.a.x-p.x) <= eps  
                        || delta > eps && K2 < eps && (lin1.a.x-lin2.a.x)*(lin1.a.x-p.x) <= eps  
                        || delta < eps && K2 < eps && (lin2.a.x-lin1.a.x)*(lin2.a.x-p.x) <= eps)  
						area = eps;  
					else {
						if (lin1.a.y-lin2.a.y>eps){
					       double K=(lin1.b.y-lin1.a.y)/(lin1.b.x-lin1.a.x);
				           double B=lin1.b.y-K*lin1.b.x;
		                   lin1.a.x=(lin2.a.y-B)/K;
		                   lin1.a.y=lin2.a.y;
				        }else{
					       double K=(lin2.b.y-lin2.a.y)/(lin2.b.x-lin2.a.x);
		                   double B=lin2.b.y-K*lin2.b.x;
						    lin2.a.x=(lin1.a.y-B)/K;
						    lin2.a.y=lin1.a.y;
			          	}
						area=xmul(lin1.a,lin2.a,p);
					}
				}
				else {
					if (lin1.a.y-lin2.a.y>eps){
						  if (fabs(lin1.a.x-lin1.b.x)>eps){
					         double K=(lin1.b.y-lin1.a.y)/(lin1.b.x-lin1.a.x);
				             double B=lin1.b.y-K*lin1.b.x;
		                     lin1.a.x=(lin2.a.y-B)/K;
		                     lin1.a.y=lin2.a.y;
					      }else lin1.a.y=lin2.a.y;
				        }else{
							if (fabs(lin2.a.x-lin2.b.x)>eps){
					         double K=(lin2.b.y-lin2.a.y)/(lin2.b.x-lin2.a.x);
		                     double B=lin2.b.y-K*lin2.b.x;
						      lin2.a.x=(lin1.a.y-B)/K;
						      lin2.a.y=lin1.a.y;
						    }else lin2.a.y=lin1.a.y;
			          	}
					area=xmul(lin1.a,lin2.a,p);
				}
			}else{
					if (lin1.a.y-lin2.a.y>eps){
						  if (fabs(lin1.a.x-lin1.b.x)>eps){
					         double K=(lin1.b.y-lin1.a.y)/(lin1.b.x-lin1.a.x);
				             double B=lin1.b.y-K*lin1.b.x;
		                     lin1.a.x=(lin2.a.y-B)/K;
		                     lin1.a.y=lin2.a.y;
					      }else lin1.a.y=lin2.a.y;
				        }else{
							if (fabs(lin2.a.x-lin2.b.x)>eps){
					         double K=(lin2.b.y-lin2.a.y)/(lin2.b.x-lin2.a.x);
		                     double B=lin2.b.y-K*lin2.b.x;
						      lin2.a.x=(lin1.a.y-B)/K;
						      lin2.a.y=lin1.a.y;
						    }else lin2.a.y=lin1.a.y;
			          	}
					area=xmul(lin1.a,lin2.a,p);
			}
				if (area<eps)area=fabs(area);
		}else area=eps;
		printf("%.2lf\n",area*0.5);
	}
	return 0;
}