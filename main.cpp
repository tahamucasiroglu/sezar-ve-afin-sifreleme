#include <locale.h> 
#include <iostream>
#include <string>


using namespace std;




string k_alfabe="abcçdefgğhıijklmnoöprsştuüvyz";
string b_alfabe="ABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZ";
string ornek_alfabe="A B C Ç D E F G Ğ H I İ J K L M N O Ö P R S Ş T U Ü V Y Z";
string ornek_alfabe2="a b c ç d e f g ğ h ı i j k l m n o ö p r s ş t u ü v y z";
//ü=129 Ü=154 i=105 İ=152 ş=159 Ş=158 ç=135 Ç=128 ö=148 Ö= 153 ğ=167 Ğ=166 boşluk=32 enter=10
//test girdisi üÜğĞiİşŞçÇöÖ test edildi ve bu girdilerde çalışıyor


int size,temp[10000],n,a,b,*tut,boyut,z;
string metin,temp_metin;



void metin_al(){//türkçe karakter sıkıntısından dolayı böyle bir fonksiyon yazdım

	for(int i=0;i<10000;i++){
		scanf("%c",&temp[i]);
		if(temp[i]==10){
			size=i;
			break;
		}
	}
	for(int i=0;i<size;i++){
		switch(temp[i]){
			case 129:
				metin+="ü";
				break;
			case 154:
				metin+="Ü";
				break;
			case 152:
				metin+="İ";
				break;
			case 159:
				metin+="ş";
				break;
			case 158:
				metin+="Ş";
				break;
			case 135:
				metin+="ç";
				break;
			case 128:
				metin+="Ç";
				break;
			case 148:
				metin+="ö";
				break;
			case 153:
				metin+="Ö";
				break;
			case 167:
				metin+="ğ";
				break;
			case 166:
				metin+="Ğ";
				break;
			default:
				metin+=(char)temp[i];
				break;
		}
	}
}

void sezar_sifrele(){
	
	cout<<"Sezar şifreleme türkçe alfabesine göre hazırlanmıştır.\nÖrnek alfabe:\n"<<endl;
	cout<<ornek_alfabe<<"\n"<<ornek_alfabe2<<endl;
	cout<<"Lütfen kaydırma değeri olan N değerini giriniz.Eğer negatif bir değer girilirse alfabade ters yönde kaydırma yapılmaktadır. Örneğin N=2 A=C olurken, N=-2 C=A olmaktadır \nN=";
	cin>>n;
	cout<<endl;
	cout<<"Lütfen şifrelenecek metini giriniz;"<<endl;
	cin.ignore();//cin i boşaltık ki metin alımına etki etmesin diye
	metin_al();
	if(n==0){
		cout<<"n=0 değeri metnin kendisi demektir"<<endl;
	}
	n<0 ? n+=29 : n=n;
	
	for(int i=0;i<metin.length();i++){
		for(int j=0;j<29;j++){
			if(metin[i]==k_alfabe[j]){
				temp_metin+=k_alfabe[(j+n)%29];
				break;
			}else if(metin[i]==b_alfabe[j]){
				temp_metin+=b_alfabe[(j+n)%29];
				break;
			}else if(temp[i]==32){
				temp_metin+=metin[i];
				break;
			}
		}
	}
	
	cout<<"\nŞifrelenmiş metin:"<<endl;
	cout<<temp_metin;
	temp_metin.erase();
	metin.erase();
}
void tum_durum(int p){
	
	for(int i=0;i<metin.length();i++){
		for(int j=0;j<29;j++){
			if(metin[i]==k_alfabe[j]){
				temp_metin+=k_alfabe[(j+p)%29];
				break;
			}else if(metin[i]==b_alfabe[j]){
				temp_metin+=b_alfabe[(j+p)%29];
				break;
			}else if(temp[i]==32){
				temp_metin+=metin[i];
				break;
			}
		}
	}
	cout<<"n="<<p<<" veya n="<<p-29<<" değeri için "<<temp_metin<<endl;
	temp_metin.erase();
}

void sezar_coz(){
	cout<<"Lütfen girilecek mesaj türk alfabesi karakterlerine göre hazırlanmış olsun"<<endl;
	cout<<"kaydırma değeri olan N değerini giriniz. eğer 0 değeri girerseniz tüm ihtimaller gösterilir ve negatif değerde ters yönde kaydırma yapar"<<endl;
	cout<<"N=";
	cin>>n;
	cout<<"\nLütfen çözülecek mesajı giriniz"<<endl;
	cin.ignore();//cin i boşaltık ki metin alımına etki etmesin diye
	metin_al();
	if(n==0){
		for(int i=1;i<29;i++){
		tum_durum(i);
	}
	temp_metin.erase();
	metin.erase();
	}else{
	n<0 ? n+=29 : n=n;
	for(int i=0;i<metin.length();i++){
		for(int j=0;j<29;j++){
			if(metin[i]==k_alfabe[j]){
				temp_metin+=k_alfabe[(j+n)%29];
				break;
			}else if(metin[i]==b_alfabe[j]){
				temp_metin+=b_alfabe[(j+n)%29];
				break;
			}else if(temp[i]==32){
				temp_metin+=metin[i];
				break;
			}
		}
	}
	cout<<"\nçözülen metin:"<<endl;
	cout<<temp_metin;
	temp_metin.erase();
	metin.erase();
}
}
bool asal_mi(int sayi1,int sayi2){
	int buyuk, kucuk, kontrol=0, i;
	if ( sayi1 < 1 || sayi2 < 1){
        printf("Lutfen pozitif tam sayi giriniz!!!");
        return false;
    }
    else if ( sayi1 == 1 || sayi2 == 1){
        return false;
    }
    
    if (sayi1 > sayi2){        //Küçük ve büyük sayıları buluyoruz
        buyuk = sayi1;
        kucuk = sayi2;
    }
    else{
        buyuk = sayi2;
        kucuk = sayi1;        
    }
    
    for(i=2; i<=kucuk; i++){
        if( (buyuk % i == 0) && (kucuk % i == 0) ){
            kontrol = 1;    // Herhangi bir sayıyıa bölündü ile kontrol 1 olur
            break;            // Diğer sayılara bölmeye gerek kalmadığı için döngüden çıkılır
        }
    }
    
    if(kontrol == 1)
        return false;
    
    else
        return true;
	
	
}

//dkphy ydkd PAFDÜMUSJÖZ

void afin_sifrele(){
	cout<<"afin şifreleme de işlem için a ve b değerleri gereklidir. Maalesef küçü ve büyük harf ayrımı olmayacaktır. Lütfen bu değerleri giriniz\na değeri=";
	cin>>a;
	cout<<"\nb değeri=";
	cin>>b;
	cout<<"\n girdiğiniz değerin işlem denklemi E(x)="<<a<<"x+"<<b<<"(mod29)'dur.'"<<endl;
	if(asal_mi(29,a)==false){
		cout<<"girilen a değeri alfabe sayısı olan 29 ile aralarında asal olmalı"<<endl;
	}else{
		cout<<"lütfen şifrelenecek metini giriniz:"<<endl;
		metin.clear();
		temp_metin.clear();
		cin.ignore();
		metin_al();
		tut=new int[metin.length()];
		boyut=metin.length();
		for(int i=0;i<metin.length();i++){
			for(int j=0;j<29;j++){
				if((int)metin[i]==32){
					tut[i]=32;
					break;
				}else if(metin[i]==k_alfabe[j]){
					tut[i]=j;
					break;
				}else if(metin[i]==b_alfabe[j]){
					tut[i]=j;
					break;
				}
			}
		}
		for(int i=0;i<metin.length();i++){
			if(tut[i]==32){
				continue;
			}else{
				tut[i]=(a*tut[i]+b)%29;
			}
		}
		
		for(int i=0;i<boyut;i++){
			if(tut[i]==32){
				temp_metin+=" ";
			}else{
				temp_metin+=b_alfabe[tut[i]];
			}
		}
		cout<<"\nşifrelenmiş metin\n"<<temp_metin;
		metin.clear();
		temp_metin.clear();
		delete tut;		
	}
}

void afin_coz(){
	cout<<"lütfen a ve b değerlerini giriniz\na değeri=";
	cin>>a;
	cout<<"\nb değeri=";
	cin>>b;
	cout<<"\nLütfen çözülecek şifreli metni giriniz"<<endl;
	metin.clear();
	temp_metin.clear();
	cin.ignore();
	metin_al();
	
	tut=new int[metin.length()];
	boyut=metin.length();
	for(int i=0;i<metin.length();i++){
		for(int j=0;j<29;j++){
			if((int)metin[i]==32){
				tut[i]=32;
				break;
			}else if(metin[i]==k_alfabe[j]){
				tut[i]=j;
				break;
			}else if(metin[i]==b_alfabe[j]){
				tut[i]=j;
				break;
			}
		}
	}
	for(int i=0;i<k_alfabe.length();i++){
		if((a*i)%29==1){
			z=i;
			break;
		}
	}
	for(int i=0;i<metin.length();i++){
		if(tut[i]==32){
			continue;
		}else{
			tut[i]=((tut[i]-b)*z)%29;
		}
	}
	
	for(int i=0;i<metin.length();i++){
		if(tut[i]<0){
			tut[i]+=29;//kendim buldum internette yazmıyor bu sayede -8 gibi çıkan sonuçlar orjinal değere döner
		}
		if(tut[i]==32){
			temp_metin+=" ";
		}else{
			temp_metin+=b_alfabe[tut[i]];
		}
		
	}	
	cout<<"\nşifresi çözülmüş metin\n"<<temp_metin<<endl;
		metin.clear();
		temp_metin.clear();	
		delete tut;	

}


int main(){
	bas:
	int karar;
	setlocale(LC_ALL, "Turkish"); 

	cout<<"Lütfen işlem seçiniz"<<endl;
	cout<<"1-sezar şifreleme"<<endl;
	cout<<"2-sezar şifre çözme"<<endl;
	cout<<"3-afin şifreleme"<<endl;
	cout<<"4-afin şifre çözme"<<endl;
	cout<<"Kararınız=";
	cin>>karar;
	cout<<endl;
	switch(karar){
		case 1:
			sezar_sifrele();
			break;
		case 2:
			sezar_coz();
			break;
		case 3:
			afin_sifrele();
			break;
		case 4:
			afin_coz();
			break;
		default:
			cout<<"geçerli değer giriniz"<<endl;
			goto bas;
			break;
	}
	
	cout<<"\n\nbaşka işlem yapmak istiyormusunuz? 1-evet 2-hayır   =";
	cin>>karar;
	if(karar==1){
		goto bas;
	}
	
	

	
	return 0;
}
