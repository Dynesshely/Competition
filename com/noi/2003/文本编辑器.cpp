/*
    题目描述
    很久很久以前，DOS3.xDOS3.x 的程序员们开始对 EDLINEDLIN 感到厌倦。于是，人们开始纷纷改用自己写的文本编辑器⋯⋯
    多年之后，出于偶然的机会，小明找到了当时的一个编辑软件。进行了一些简单的测试后，小明惊奇地发现：那个软件每秒能够进行上万次编辑操作（当然，你不能手工进行这样的测试） ！于是，小明废寝忘食地想做一个同样的东西出来。你能帮助他吗？
    为了明确目标，小明对“文本编辑器”做了一个抽象的定义:
    文本：由 00 个或多个 ASCII 码在闭区间 [3232, 126126] 内的字符构成的序列。
    光标：在一段文本中用于指示位置的标记，可以位于文本首部，文本尾部或文本的某两个字符之间。
    文本编辑器：由一段文本和该文本中的一个光标组成的，支持如下操作的数据结构。如果这段文本为空，我们就说这个文本编辑器是空的。
    操作名称	输入文件中的格式	功能
    \text{Move}(k)Move(k)	Move k	将光标移动到第 kk 个字符之后，如果 k=0k=0，将光标移到文本开头
    \text{Insert}(n,s)Insert(n,s)	Insert n s	在光标处插入长度为 nn 的字符串 ss，光标位置不变n\geq1n≥1
    \text{Delete}(n)Delete(n)	Delete n	删除光标后的 nn 个字符，光标位置不变，n \geq 1n≥1
    \text{Get}(n)Get(n)	Get n	输出光标后的 nn 个字符，光标位置不变，n \geq 1n≥1
    \text{Prev}()Prev()	Prev	光标前移一个字符
    \text{Next}()Next()	Next	光标后移一个字符
    你的任务是：
    建立一个空的文本编辑器。
    从输入文件中读入一些操作并执行。
    对所有执行过的 GET 操作，将指定的内容写入输出文件。

    输入格式
    输入文件 editor.in 的第一行是指令条数 tt，以下是需要执行的 tt 个操作。其中：
    为了使输入文件便于阅读， Insert 操作的字符串中可能会插入一些回车符， 请忽略掉它们（如果难以理解这句话，可以参照样例） 。
    除了回车符之外，输入文件的所有字符的 ASCII 码都在闭区间 [3232, 126126] 内。且
    行尾没有空格。
    这里我们有如下假定：
    MOVE 操作不超过 5000050000 个， INSERT 和 DELETE 操作的总个数不超过 40004000，PREV 和 NEXT 操作的总个数不超过 200000200000。
    所有 INSERT 插入的字符数之和不超过 2M2M（1M=1024\times 10241M=1024×1024 字节） ，正确的输出文件长度不超过 3M3M 字节。
    DELETE 操作和 GET 操作执行时光标后必然有足够的字符。 MOVE 、 PREV 、 NEXT 操作必然不会试图把光标移动到非法位置。
    输入文件没有错误。

    对 C++ 选手的提示：经测试，最大的测试数据使用 fstream 进行输入有可能会比使用 stdio 慢约 11 秒。

    输出格式
    输出文件 editor.out 的每行依次对应输入文件中每条 Get 指令的输出。
*/

#include <bits/stdc++.h>
using namespace std;
int cursor = 0, length = 0; // cursor: 光标位置，length: 文本长度

/*
    用双向链表维护一个字符串
    方便查找，插入，删除
*/

struct node{ // 双向链表结点
    char c;
    node *next, *prev;
}*now; // 当前 cursor 对应的结点

void insert(node *bf, node *af, char c){ // 插入字符
    node *insertto = new node; insertto->c = c; // 创建新结点并赋值
    bf->next = insertto, af->prev = insertto; // 解开并设置前结点和后结点的后指针
    insertto->prev = bf, insertto->next = af; // 设置插入结点的前指针和后指针
}

// 插入字符串 - 返回块状链表的首结点指针和尾结点指针
node** insert_alot(node *bf, string str){
    // 生成块状链表
    int length = str.length();
    node *part[length];
    for(int i = 0; i < length; ++ i){
        part[i] = new node;
        part[i]->c = str[i];
    }
    for(int i = 0; i < length; ++ i){
        part[i]->next = i + 1 >= length ? NULL : part[i + 1];
        part[i]->prev = i - 1 < 0 ? NULL : part[i - 1];
    }
    // 插入到原链表中
    part[length - 1]->next = bf->next, bf->next->prev = part[length - 1];
    part[0]->prev = bf, bf->next = part[0];
    return part;
}

void check_now(node *head, node *tail){ // 检查当前光标所在位置是否合法
    if(now == head) now = now->next;
    if(now == tail) now = now->prev;
}

int t, tmp_cur, insert_num, delete_num, get_num; // 临时数据集
int main(){
    scanf("%d", &t);
    node *head = new node; // 首结点
    node *tail = new node; // 尾结点
    head->next = tail, head->prev = NULL;
    tail->prev = head, tail->next = NULL;
    now = head;
    for(int i = 0; i < t; ++ i){
        string cmd;
        cin >> cmd;
        if(cmd == "Move"){ // 移动光标并计算和位移当前字符指针
            scanf("%d", &tmp_cur);
            int delta = tmp_cur - cursor;
            bool pre = delta < 0;
            for(int i = 0; i < abs(delta); ++ i)
                now = pre ? now->prev : now->next;
            cursor = tmp_cur;
            // check_now(head, tail);

            // if(tmp_cur > cursor) for(int j = cursor; j < tmp_cur; ++ j) now = now->next;
            // else for(int j = tmp_cur; j > cursor; -- j) now = now->prev;
            // if(now->prev == NULL) now = now->next;
            // else if(now->next == NULL) now = now->prev;
            // cursor = tmp_cur;
        }else if(cmd == "Prev"){ // 向前一个光标
            cursor = cursor == 0 ? 0 : cursor - 1;
            now = now->prev == NULL ? now : now->prev;
            // if(now->prev == NULL) now = now->next; // 到达链表头返回第一个字符
            // check_now(head, tail);
        }else if(cmd == "Next"){ // 向后一个光标
            cursor = cursor == length ? length : cursor + 1;
            now = now->next == NULL ? now : now->next;
            // if(now->next == NULL) now = now->prev; // 到达链表尾返回最后一个字符
            // check_now(head, tail);
        }else if(cmd == "Insert"){ // 插入字符串
            scanf("%d", &insert_num);
            string tmp;
            char c;
            for(int i = 0; i < insert_num; ++ i){
                c = cin.get();
                if(c == '\n') -- i;
                else if(c == '\r') -- i;
                else tmp += c;
            }
            insert_alot(now, tmp);
        }else if(cmd == "Delete"){
            node *tmp = now;
            scanf("%d", &delete_num);
            for(int i = 0; i < delete_num; ++ i)
                tmp = tmp->next == NULL ? tmp : tmp->next;
            if(now->next == NULL) now = now->prev; // 到达链表尾返回最后一个字符
            now->next = tmp->next, tmp->next->prev = now;
        }else if(cmd == "Get"){
            string rst;
            node *tmp = now;
            scanf("%d", &get_num);
            for(int i = 0; i < get_num; ++ i)
                tmp = tmp->next == NULL ? tmp : tmp->next, rst += tmp->c;
            cout << rst << endl;
        }
    }
    return 0;
}

