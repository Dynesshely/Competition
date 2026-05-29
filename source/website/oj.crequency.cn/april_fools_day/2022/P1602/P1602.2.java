import java.text.*;class a{public static void main(String x[]){char b[]={34};
char c[]={123};String s[]=new String[3];s[0]="import java.text.*;class a{2}
public static void main(String x[]){2}char b[]={2}34};char c[]={2}123};
String s[]=new String[3];s[0]={1}{0}{1};s[1]=new String(b);s[2]=new String(c);
System.out.println(MessageFormat.format(s[0],s));}}";s[1]=new String(b);s[2]=
new String(c);System.out.println(MessageFormat.format(s[0],s));}}