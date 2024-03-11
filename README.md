

# DataStructure

数据结构代码实现

## lesson3 顺序表和链表

### 1.线性表

线性表（linear list）是n个具有相同特性的数据元素的有限序列。线性表是一种在实际中广泛使用的数据结构，**常见的线性表：顺序表、链表、栈、队列、字符串……**

线性表在逻辑上是线性结构，也就说是连续的一条直线。但是在物理结构上并不一定是连续的，线性表在物理上存储时，通常以数组和链式结构的形式存储。![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1705677458972-ebf4c452-ca2b-4025-8a38-ad6891fb6cdb.png#averageHue=%23f6f6f6&clientId=uae9925aa-122f-4&from=paste&height=267&id=uf27f8f90&originHeight=401&originWidth=1027&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=40060&status=done&style=none&taskId=uf2eeda99-be92-42d4-901c-911e47ccbe0&title=&width=684.6666666666666)

### 2.顺序表

顺序表是用一段物理地址连续的存储单元依次存储数据元素的线性结构，一般情况下采用数组存储。在数组上完成数据的增删查改。

①静态顺序表：使用定长数组存储元素![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1705677528266-9823b2d1-fa36-4331-8351-f0649a8d2c31.png#averageHue=%23fcfbfb&clientId=uae9925aa-122f-4&from=paste&height=309&id=ue970a355&originHeight=617&originWidth=822&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=115440&status=done&style=none&taskId=u915ec24c-ae72-46e6-9d68-d9c72ecb96d&title=&width=411)②动态顺序表：使用动态开辟的数组存储![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1705677565701-2a291d2c-df02-41a8-8f19-de08b57a5c8a.png#averageHue=%23fcfbfb&clientId=uae9925aa-122f-4&from=paste&height=276&id=uea214be6&originHeight=552&originWidth=906&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=130183&status=done&style=none&taskId=ua24c387d-74ed-42e4-80a2-3559dd1ffb5&title=&width=453)


### 3.链表

概念：链表是一种物理存储结构上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1705677633128-9033bf61-804c-4b5d-a436-106cce39cf5d.png#averageHue=%23f5f4f4&clientId=uae9925aa-122f-4&from=paste&height=536&id=u6030c968&originHeight=804&originWidth=859&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=154734&status=done&style=none&taskId=u74e966aa-2f04-4538-998a-d4c2b94bed0&title=&width=572.6666666666666)**3.1 链表的分类**

实际中链表的结构非常多样，以下情况组合起来就有**8种链表结构**：

①单向或者双向![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1705677743886-ca958c96-c004-4796-ae57-4510f5d2c4a5.png#averageHue=%23f3f3f3&clientId=uae9925aa-122f-4&from=paste&height=140&id=u44718215&originHeight=216&originWidth=813&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=38603&status=done&style=shadow&taskId=u88b70a7f-c768-485b-ac12-ea54a85b2c8&title=&width=527)②带头或者不带头![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1705677757034-baadce05-381c-4e62-ac4b-77913118fbce.png#averageHue=%23f3f3f3&clientId=uae9925aa-122f-4&from=paste&height=135&id=u455aa26e&originHeight=203&originWidth=790&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=37240&status=done&style=shadow&taskId=u143178bb-53a5-4049-8139-f40542bfcc5&title=&width=526.6666666666666)③循环或者非循环![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1705677772567-a5d5a3f3-f7a5-4c4f-977e-a87a991c1fa3.png#averageHue=%23f5f5f5&clientId=uae9925aa-122f-4&from=paste&height=171&id=u561db033&originHeight=243&originWidth=748&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=34043&status=done&style=shadow&taskId=ufe91c089-d59b-4b2a-9d23-bba647938e2&title=&width=525.6666870117188)

> 虽然有这么多的链表的结构，但是我们实际中**最常用还是两种结构**：

- **无头单向非循环链表**

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1705677828208-dbec46bc-2dba-435e-a649-d9503355fd1a.png#averageHue=%23f4f4f4&clientId=uae9925aa-122f-4&from=paste&height=63&id=u2bebf5ba&originHeight=95&originWidth=488&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=12225&status=done&style=none&taskId=ubabbbe27-cec7-4cfb-96b6-9c5382e6855&title=&width=325.3333333333333)无头单向非循环链表：**结构简单**，一般不会单独用来存数据。实际中更多是作为**其他数据结构的子结构**，如哈希桶、图的邻接表等等。另外这种结构在**笔试面试**中出现很多。

- **带头双向循环链表**

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1705677839377-b372e524-5276-4df4-a1b1-17e5b270d0db.png#averageHue=%23f1f1f1&clientId=uae9925aa-122f-4&from=paste&height=95&id=u72cebbab&originHeight=142&originWidth=844&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=29273&status=done&style=none&taskId=ua86be2ff-d65f-4294-bdd9-c06894fd84a&title=&width=562.6666666666666)带头双向循环链表：**结构最复杂**，一般用在单独存储数据。实际中使用的链表数据结构，都是带头双向循环链表。另外这个结构虽然结构复杂，但是使用代码实现以后会发现结构会带来很多优势，实现反而简单了，后面我们代码实现了就知道了。

> 小记tip：
> **全局变量**或者**静态**存储都在数据段上，而在函数内部临时开辟的则存储在栈区（记忆技巧：栈区后来先出，生命周期短，适合存储临时使用的变量，在函数执行结束时会自动被释放），堆区存放的则是在函数运行过程中开辟出来的空间，需要程序员进行手动分区以及释放，也可能程序结束时由OS回收，所以也可能会发生内存泄漏问题

### 4.顺序表和链表的区别和联系

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1708076523625-80a3ff66-1667-4556-8e11-c5fcf23add06.png#averageHue=%23f7f7f6&clientId=u1b16fbec-95c9-4&from=paste&height=387&id=uf61e91b9&originHeight=580&originWidth=1108&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=177156&status=done&style=none&taskId=u07f8d8aa-4c29-4b34-928e-197fe2a7888&title=&width=738.6666666666666)

## lesson4 栈和队列

### 1.栈

①栈的概念和结构

栈：一种特殊的线性表，其只允许**在固定的一端进行插入和删除元素操作**。进行数据插入和删除操作的一端称为栈顶，另一端称为栈底。栈中的数据元素遵守**后进先出**LIFO(Last In First Out)的原则。

压栈：栈的插入操作叫做进栈/压栈/入栈，入数据在栈顶。

出栈：栈的删除操作叫做出栈。出数据也在栈顶。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1708955323580-0f9d8475-8d61-4212-b3fe-4acb9226da80.png#averageHue=%23f5f0e2&clientId=u5e4fe7c2-cd20-4&from=paste&height=252&id=ue955a40c&originHeight=532&originWidth=1234&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=86846&status=done&style=none&taskId=u2af3a20c-e5e1-4aa9-b43f-d93a67b6c67&title=&width=584)

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1708955348294-a2b7e318-1cf3-49b4-8af7-c1554a184fa3.png#averageHue=%23f9f9f9&clientId=u5e4fe7c2-cd20-4&from=paste&height=619&id=u061907c2&originHeight=1046&originWidth=1090&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=161065&status=done&style=none&taskId=ua8149edd-1e9f-481a-930d-83793ff0673&title=&width=645)

② 栈的实现

栈的实现一般可以使用**数组或者链表**实现，相对而言数组的结构实现更优一些。因为数组在尾上插入数据的代价比较小。

**数组栈**：

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1708955466552-93984218-438d-4237-9889-08688f7b64d7.png#averageHue=%23f9f9f8&clientId=u5e4fe7c2-cd20-4&from=paste&height=204&id=u0afa426c&originHeight=306&originWidth=1252&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=64287&status=done&style=shadow&taskId=uc8987dc5-b3d4-4966-9ac0-6505f3b4885&title=&width=834.6666666666666)

**链表栈（此图为单链表，双链表栈顶可以是头也可以是尾）**：

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1708955555564-3a82c0a7-6802-4c3f-a129-c6b0cb9c3a98.png#averageHue=%23f7f7f7&clientId=u5e4fe7c2-cd20-4&from=paste&height=404&id=u517f9978&originHeight=606&originWidth=1162&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=126078&status=done&style=shadow&taskId=u9794ef83-328b-42cc-98f0-046fcbcceb7&title=&width=774.6666666666666)

### 2.队列

①队列的概念及结构

队列：只允许在一端进行插入数据操作，在另一端进行删除数据操作的特殊线性表，队列具有先进先出FIFO(First In First Out)

入队列：进行插入操作的一端称为队尾

出队列：进行删除操作的一端称为队头

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709136243628-a7e854df-44e9-4445-9002-a5812104cc93.png#averageHue=%23f9f9f9&clientId=u78410810-68e2-4&from=paste&height=173&id=u5dbceeb4&originHeight=259&originWidth=954&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=28609&status=done&style=shadow&taskId=u447af6b6-7836-4e71-b46d-91dbca7188f&title=&width=636)

②队列的实现

队列也可以数组和链表的结构实现，使用链表的结构实现更优一些，因为如果使用数组的结构，出队列在数组头上出数据，效率会比较低。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709136338439-a987e2c8-e8a0-4317-b3ff-b938ccac7a14.png#averageHue=%23f2f1f1&clientId=u78410810-68e2-4&from=paste&height=408&id=u6193d2a2&originHeight=595&originWidth=921&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=476993&status=done&style=shadow&taskId=u7db37e77-39fc-4def-ae39-46654b571b0&title=&width=631)

> 另外扩展了解一下，实际中我们有时还会使用一种队列叫循环队列。如操作系统课程讲解生产者消费者模型时可以就会使用循环队列。环形队列可以使用数组实现，也可以使用循环链表实现。
> ![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709136874168-0bb9e7d2-f15e-46d4-b1bd-b7c833f05f18.png#averageHue=%23faf9f9&clientId=u429afee4-bb7e-4&from=paste&height=166&id=u1c589eb5&originHeight=485&originWidth=933&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=109412&status=done&style=shadow&taskId=uc022aa86-1861-4c43-ab3e-f4ea786fcd6&title=&width=319)![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709136917440-590f6381-7ecc-4540-957e-4f7f013c1a23.png#averageHue=%23ecebe7&clientId=u429afee4-bb7e-4&from=paste&height=173&id=ub125b0a7&originHeight=408&originWidth=963&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=255944&status=done&style=shadow&taskId=ue6e0a282-b90d-412a-99a4-23547a0502c&title=&width=409)



## lesson5 二叉树

### 1.树

①树的概念

树是一种非线性的数据结构，它是由(>=0)个有限结点组成一个具有层次关系的集合。把它叫做树是因为它看起来像一棵倒挂的树，也就是说它是根朝上，而叶朝下的。

- 有一个特殊的结点，称为根结点，根节点没有前驱结点
- 除根节点外，其余结点被分成M(M>0)个互不相交的集合T1、T2、、Tm,其中每一个集合Ti(1<=i<=)又是一棵结构与树类似的子树。每棵子树的根结点有且只有一个前驱，可以有0个或多个后继
- 因此，树是递归定义的。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709472368363-c712d52e-9ce2-40f6-b521-2ab8ac74d99b.png#averageHue=%23fbfbfb&clientId=uc77d0253-8e5c-4&from=paste&height=317&id=u98e2783b&originHeight=475&originWidth=706&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=71557&status=done&style=none&taskId=u10871ba1-f1c4-42b8-afab-bd2e9d36577&title=&width=470.6666666666667)

> 注意：树形结构中，子树之间不能有交集，否则就不是树形结构
> ![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709472421340-5f409dd5-0e66-4447-a265-85708dde3b05.png#averageHue=%23eeeeee&clientId=uc77d0253-8e5c-4&from=paste&height=283&id=uc23582c7&originHeight=424&originWidth=650&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=135542&status=done&style=none&taskId=ufe3bd7b9-6dc7-41f8-92fb-72d25ecf0bb&title=&width=433.3333333333333)

②树的相关概念

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709472452709-b3db4477-39b7-4e47-b0fe-384a42978225.png#averageHue=%23fdfdfd&clientId=uc77d0253-8e5c-4&from=paste&height=252&id=ue64e8510&originHeight=378&originWidth=981&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=151320&status=done&style=none&taskId=u46767d0c-60d8-415c-823e-a973b4c45f3&title=&width=654)

- **节点的度**：一个节点含有的子树的个数称为该节点的度；如上图：A的为6
- **叶节点或终端节点**：度为O的节点称为叶节点；如上图：B、C、H、I等节点为叶节点
- **非终端节点或分支节点**：度不为0的节点；如上图：D、E、F、G.等节点为分支节点
- **双亲节点或父节点**：若一个节点含有子节点，则这个节点称为其子节点的父节点；如上图：A是B的父节点
- **孩子节点或子节点**：一个节点含有的子树的根节点称为该节点的子节点；如上图：B是A的孩子节点
- **兄弟节点**：具有相同父节点的节点互称为兄弟节点；如上图：B、C是兄弟节点
- **树的度**：一棵树中，最大的节点的度称为树的度；如上图：树的度为6
- **节点的层次**：从根开始定义起，根为第1层，根的子节点为第2层，以此类推
- **树的高度或深度**：树中节点的最大层次；如上图：树的高度为4
- **堂兄弟节点**：双亲在同一层的节点互为堂兄弟；如上图：A、互为兄弟节点
- **节点的祖先**：从根到该节点所经分支上的所有节点如上图：A是所有节点的祖先
- **子孙**：以某节点为根的子树中任一节点都称为该节点的子孙。如上图：所有节点都是A的子孙
- **森林**：由m(m>0)棵互不相交的树的集合称为森林；

③树的表示

树结构相对线性表就比较复杂了、要存储表示起来就比较麻烦了，既然保存值域，也要保存结点和结点之间的关系，实际中树有很多种表示方式如：双亲表示法，孩子表示法、孩子双亲表示法以及孩子兄弟表示法等。我们这里就简单的了解其中最常用的孩子兄弟表示法。

```
typedef int DataType;
struct Node
{
    struct Node* _firstChild1;       //第一个孩子结点
    struct Node* _pNextBrother;      //指向其下一个兄弟结点
    DataType_data;                   //结点中的数据域
}
```

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709472867105-f55d5861-4b25-4e1a-a721-1dae8a29791f.png#averageHue=%23fdfbfb&clientId=uc77d0253-8e5c-4&from=paste&height=242&id=u9e675eed&originHeight=363&originWidth=1285&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=95507&status=done&style=none&taskId=u8e803133-32e5-4ad6-a434-1e9490fb684&title=&width=856.6666666666666)

④树在实际中的运用

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709472916849-bbc6468a-218b-42e9-830f-742682a4f27c.png#averageHue=%237db9e1&clientId=uc77d0253-8e5c-4&from=paste&height=321&id=ue940b0dd&originHeight=481&originWidth=1044&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=344689&status=done&style=none&taskId=u28409849-7296-4b1f-98fa-72ec7e342dc&title=&width=696)

### 2.二叉树

①概念

一棵二叉树是结点的一个有限集合，该集合：

1.或者为空

2.由一个根节点加上两棵别称为左子树和右子树的二叉树组成

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709601971940-b50ccacb-872b-4754-a9bc-d2632e8a924e.png#averageHue=%23e7f2f6&clientId=u7f776361-b5ee-4&from=paste&height=188&id=u08856307&originHeight=376&originWidth=935&originalType=binary&ratio=2&rotation=0&showTitle=false&size=69344&status=done&style=none&taskId=uba23f9c5-883c-4d01-a654-a072cb4ccd4&title=&width=467.5)

从上图可以看出：

1.二叉树不存在度大于2的结点

2.二叉树的子树有左右之分，次序不能颠倒，因此二叉树是有序树

注意：对于任意的二叉树都是由以下几种情况复合而成的：

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709602074492-e580c4d0-0628-4696-a26d-1113b4426cda.png#averageHue=%23f2f2f2&clientId=u7f776361-b5ee-4&from=paste&height=126&id=u589b6939&originHeight=251&originWidth=765&originalType=binary&ratio=2&rotation=0&showTitle=false&size=50042&status=done&style=none&taskId=uf1534fa1-218d-4bf4-b8b0-85b4a9a5e6b&title=&width=382.5)

②特殊的二叉树

（1）满二叉树：一个二叉树，如果每一个层的结点数都达到最大值，则这个二叉树就是满二叉树。也就是说，如果一个二叉树的层数为K,且结点总数是2一1，则它就是满二叉树。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709602156214-f6ba5bdb-9090-41fa-85d5-b7762622cfeb.png#averageHue=%23f8f8f8&clientId=u7f776361-b5ee-4&from=paste&height=112&id=u0262a5bd&originHeight=224&originWidth=338&originalType=binary&ratio=2&rotation=0&showTitle=false&size=29048&status=done&style=none&taskId=u2a3b1c24-823c-4093-a6e0-9dcdee2529e&title=&width=169)

假设高度为h，合计：2^0+2^1+2^2+……+2^(h-1) = 2^h-1

假设树有N个节点：2^h-1=N     h=log2(N+1)

（2）完全二叉树：完全二叉树是效率很高的数据结构，完全二叉树是由满二叉树而引出来的。对于深度为K的，有个结点的二叉树，当且仅当其每一个结点都与深度为K的满二叉树中编号从1至的结点一一对应时称之为完全二叉树。要注意的是**满二叉树是一种特殊的完全二叉树**。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709602173837-af46a8fc-dd92-4cb2-ab04-48f730fce646.png#averageHue=%23fafafa&clientId=u7f776361-b5ee-4&from=paste&height=110&id=uc104ec5b&originHeight=219&originWidth=307&originalType=binary&ratio=2&rotation=0&showTitle=false&size=21365&status=done&style=none&taskId=u4741f508-3832-4e42-a5b1-159112fb063&title=&width=153.5)

完全二叉树高度为h，节点数是[ 2^(h-1) , 2^h-1 ]

③二叉树的性质

1. 若规定根节点的层数为1，则一棵非空二叉树的第层上最多有2^(i-1)个结点
2. 若规定根节点的层数为1，则深度为的二叉树的最大结点数是(2^h) - 1.
3. 对任何一棵二叉树，如果度为0其叶结点个数为o,度为2的分支结点个数为n2，则有n0=n2+1
4. 若规定根节点的层数为1，具有n个结点的满二叉树的深度，h=log2(n+1).(ps:log2(n+1)是1og以2为底，n+1为对数)
5. 对于具有个结点的完全二叉树，如果按照从上至下从左至右的数组顺序对所有节点从0开始编号，则对于序号为的结点有：

- 1.若 i >0，i位置节点的双亲序号：（i-1）/ 2； i=0  , i 为根节点编号，无双亲节点
- 2.若2i+1<n,左孩子序号：2i+1,  2i+1>=n否则无左孩子
- 3.若2i+2<n,右孩子序号：2i+2,  2i+2>=n否则无右孩子

④二叉树的存储结构

> 二叉树一般可以使用两种结构存储，一种顺序结构，一种链式结构。

1.顺序存储

顺序结构存储就是使用数组来存储，一般使用数组只适合表示完全二叉树，因为不是完全二叉树会有空间的浪费。而现实中使用中只有堆才会使用数组来存储，关于堆我们后面的章节会专门讲解。二叉树顺序存储在物理上是一个数组，在逻辑上是一颗二叉树。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709623858939-8468c747-8331-4678-99b8-ba9f9258ec13.png#averageHue=%23f7f7f7&clientId=ue8c5a180-a5ae-4&from=paste&height=346&id=uef7dfdc9&originHeight=519&originWidth=1319&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=210381&status=done&style=none&taskId=u64afc6f9-70c5-4b10-9edf-79eccb2a06b&title=&width=879.3333333333334)

2.链式存储

二叉树的链式存储结构是指，用链表来表示一棵二叉树，即用链来指示元素的逻辑关系。通常的方法是链表中每个结点由三个域组成，数据域和左右指针域，左右指针分别用来给出该结点左孩子和右孩子所在的链结点的存储地址。链式结构又分为二叉链和三叉链，当前我们学习中一般都是二叉链，后面课程学到高阶数据结构如红黑树等会用到三叉链。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709623916336-68f371b2-b81c-4be9-b8e8-c377cda7729d.png#averageHue=%23f4f4f4&clientId=ue8c5a180-a5ae-4&from=paste&height=625&id=uca1628dc&originHeight=938&originWidth=1267&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=341016&status=done&style=none&taskId=uc1a9174b-e315-4c37-bfab-0d6ecc39228&title=&width=844.6666666666666)

```
typedef int BTDataType;
//二叉链
struct BinaryTreeNode
{
    struct BinTreeNode* _pLeft;/指向当前节点左孩子
    struct BinTreeNode* _pRight;/指向当前节点右孩子
    BTDataType _data;//当前节点值域
}

//三叉链
struct BinaryTreeNode
{
    struct BinTreeNode* _pParent;//指向当前节点的双亲
    struct BinTreeNode* _pLeft;//指向当前节点左孩子
    struct BinTreeNode* _pRight;/指向当前节点右孩子
    BTDataType_data;//当前节点值域
}
```



### 3.二叉树的顺序结构及实现

①二叉树的顺序结构

普通的二叉树是不适合用数组来存储的，因为可能会存在大量的空间浪费。而完全二叉树更适合使用顺序结构存储。**现实中我们通常把堆（一种二叉树）使用顺序结构的数组来存储，需要注意的是这里的堆和操作系统虚拟进程地址空间中的堆是两回事，一个是数据结构，一个是操作系统中管理内存的一块区域分段。**

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709624175351-bf8fa0c5-6acd-416d-85c2-694b500f8e40.png#averageHue=%23f6f6f6&clientId=ue8c5a180-a5ae-4&from=paste&height=367&id=u389965ff&originHeight=550&originWidth=1299&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=226713&status=done&style=none&taskId=ub63757ef-cc5e-4bee-9448-c3a1da49fd2&title=&width=866)

②堆的概念及结构

如果有一个关键码的集合K={o,k1,2,…,k-1},把它的所有元素按完全二叉树的顺序存储方式存储在一个一维数组中，并满足：K:<=K2*i+1且K<=K2*+2(K>=K2*i+1且K>=K2*i+2)i=0,1,2……,则称为小堆（或大堆）。将根节点最大的堆叫做最大堆或大根堆，根节点最小的堆叫做最小堆或小根堆。

堆的性质：

- 堆中某个节点的值总是不大于或不小于其父节点的值；
- 堆总是一棵完全二叉树。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709624292597-3500d606-9a84-4aed-a3d4-cc3542471915.png#averageHue=%23eeeeee&clientId=ue8c5a180-a5ae-4&from=paste&height=365&id=u1f0ace0f&originHeight=723&originWidth=1179&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=185260&status=done&style=none&taskId=uc4f3dee6-53bd-443b-bcdf-c242397d2dc&title=&width=596)

③堆的实现

（1）向下调整算法

现在我们给出一个数组，逻辑上看做一颗完全二叉树。我们通过从根节点开始的向下调整算法可以把它调整成一个小堆。向下调整算法有一个前提：左右子树必须是一个堆，才能调整。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709653978065-24ab3435-afb9-4765-8c32-4ad11e0f1a0c.png#averageHue=%23fcfbfb&clientId=u5ebd9372-0189-4&from=paste&height=347&id=u67e59579&originHeight=521&originWidth=1301&originalType=binary&ratio=2&rotation=0&showTitle=false&size=293869&status=done&style=none&taskId=udc8b2c7d-3382-4d99-b08f-69fa521b592&title=&width=867.3333333333334)

（2）堆的创建

下面我们给出一个数组，这个数组逻辑上可以看做一颗完全二叉树，但是还不是一个堆，现在我们通过算法，把它构建成一个堆。根节点左右子树不是堆，我们怎么调整呢？这里我们从倒数的第一个非叶子节点的子树开始调整，一直调整到根节点的树，就可以调整成堆。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709654031273-a78c18ef-6a24-4797-9c90-33c8f7ae9ba0.png#averageHue=%23f1e369&clientId=u5ebd9372-0189-4&from=paste&height=505&id=uc83d82a1&originHeight=758&originWidth=1253&originalType=binary&ratio=2&rotation=0&showTitle=false&size=616440&status=done&style=none&taskId=u58af9675-435e-419e-a75e-32250723895&title=&width=835.3333333333334)

（3）建堆时间复杂度

因为堆是完全二叉树，而满二叉树也是完全二叉树，此处为了简化使用满二叉树来证明（时间复杂度本来看的就是近似值，多几个节点不影响最终结果)：

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709654089372-68890b1b-8aca-41f8-93cc-dd852aae0e7b.png#averageHue=%23f9f9f8&clientId=u5ebd9372-0189-4&from=paste&height=513&id=uc341ed85&originHeight=770&originWidth=1260&originalType=binary&ratio=2&rotation=0&showTitle=false&size=284365&status=done&style=none&taskId=ub23285c5-6f58-4c8f-8bbb-8cd31e2a781&title=&width=840)

（4）堆的插入

先插入一个10到数组的尾上，再进行向上调整算法，直到满足堆。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709654122523-1806bee8-dd08-464b-9a1c-52113b87f649.png#averageHue=%23f9f9f9&clientId=u5ebd9372-0189-4&from=paste&height=205&id=u29320904&originHeight=308&originWidth=1213&originalType=binary&ratio=2&rotation=0&showTitle=false&size=244526&status=done&style=none&taskId=u46f1a5ba-033a-4c02-ba9b-0171f31430e&title=&width=808.6666666666666)

（5）堆的删除

删除堆是删除堆顶的数据，将堆顶的数据根最后一个数据一换，然后删除数组最后一个数据，再进行向下调整算法。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709654168073-6ed76868-9fde-4c24-b02c-43614cea01a5.png#averageHue=%23fbfafa&clientId=u5ebd9372-0189-4&from=paste&height=265&id=u851ec4c6&originHeight=398&originWidth=1253&originalType=binary&ratio=2&rotation=0&showTitle=false&size=239757&status=done&style=none&taskId=u8814d7ad-ffe8-40bc-b72d-2ce46af7d7e&title=&width=835.3333333333334)

④堆的应用

> 1.堆排序
> 堆排序即利用堆的思想来进行排序，总共分为两个步骤：
> （1）建堆
> 升序：建大堆
> 降序：建小堆
> （2）利用堆删除思想来进行排序
> 建堆和堆删除中都用到了向下调整，因此掌握了向下调整，就可以完成堆排序。
> ![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709654276533-ecf0f0e6-c44f-41fa-a193-51be7f659e6a.png#averageHue=%23fafafa&clientId=u5ebd9372-0189-4&from=paste&height=747&id=uc0fed9c8&originHeight=1121&originWidth=1352&originalType=binary&ratio=2&rotation=0&showTitle=false&size=736593&status=done&style=none&taskId=u551a4ff0-4df4-436c-9b34-823d155b69f&title=&width=901.3333333333334)

> 2.TOP-K问题
> TOPK问题：即求数据结合中前K个最大的元素或者最)小的元素，一般情况下数据量都比较大。
> 比如：专业前10名、世界500强、富豪榜、游戏中前100的活跃玩家等。
> 对于ToK问题，能想到的最简单直接的方式就是排序，但是：如果数据量非常大，排序就不太可取了（可能数据都不能一下子全部加载到内存中)。最佳的方式就是用堆来解决，基本思路如下：
> （1）用数据集合中前K个元素来建堆
>
> - 前k个最大的元素，则建小堆
> - 前k个最小的元素，则建大堆
>
> （2）用剩余的N-K个元素依次与堆顶元素来比较，不满足则替换堆顶元素
> 将剩余N-K个元素依次与堆顶元素比完之后，堆中剩余的K个元素就是所求的前K个最小或者最大的元素。

```c
void PrintTopK(int*a,int n,int k)
{
    //1,建堆--用a中前k个元素建堆
    //2,将剩余-k个元素依次与堆顶元素交换，不满则则替换
}

void TestTopk()
{
    int n=10000;
    int* a = (int*)malloc(sizeof(int)*n);
    srand(time());
    for (size t i 0;i<n;++i)
    {
        a[i]=rand()%1000000;
    }
    a[5]=1000000+1;
    a[1231]=1000000+2;
    a[531]=1000000+3;
    a[5121]=1000000+4;
    a[115]=1000000+5;
    a[2335]=1000000+6;
    a[9999]=1000000+7;
    a[76]=1000000+8;
    a[423]=1000000+9;
    a[3144]=1000000+10;
    PrintTopK(a,n,10);
}
```



### 4.二叉树的链式结构及实现

①前置说明

在学习二叉树的基本操作前，需先要创建一棵二叉树，然后才能学习其相关的基本操作。由于现在大家对二叉树结构掌握还不够深入，为了降低大家学习成本，此处手动快速创建一棵简单的二叉树，快速进入二叉树操作学习，等二叉树结构了解的差不多时，我们反过头再来研究二叉树真正的创建方式。

```c
typedef int BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType _data;
    struct BinaryTreeNode* _left;
    struct BinaryTreeNode* _right;
}BTNode;

BTNode* CreatBinaryTree()
{
    BTNode* node1 BuyNode(1);
    BTNode* node2 BuyNode(2);
    BTNode* node3 BuyNode(3);
    BTNode* node4 BuyNode(4);
    BTNode* node5 BuyNode(5);
    BTNode* node6 BuyNode(6);
    
    node1->_left = node2;
    node1->_right = node4;
    node2->_left = node3;
    node4->_left = node5;
    node4->_right = node6;
    return node1;
}
```

> 注意：上述代码并不是创建二叉树的方式，真正创建二叉树方式后序详解重点讲解。
> 再看二叉树基本操作前，再回顾下二叉树的概念，二叉树是：
> 1.空树
> 2.非空：根节点，根节点的左子树、根节点的右子树组成的。
> 从概念中可以看出，二叉树定义是递归式的，因此后序基本操作中基本都是按照该概念实现的。![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709867818090-dab15773-2aa9-4a41-bb91-8870cfcdb1a1.png#averageHue=%23fbfbfb&clientId=ue5880cbc-94bc-4&from=paste&height=252&id=u02617a0b&originHeight=378&originWidth=1172&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=78435&status=done&style=none&taskId=ucff42df3-8a74-42e7-9449-510cb67090d&title=&width=781.3333333333334)

②二叉树的遍历

（1）前序、中序以及后序遍历

学习二叉树结构，最简单的方式就是遍历。所谓二叉树遍历(Traversal)是按照某种特定的规则，依次对二叉树中的节点进行相应的操作，并且每个节点只操作一次。访问结点所做的操作依赖于具体的应用问题。遍历是二叉树上最重要的运算之一，也是二叉树上进行其它运算的基础。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709867898965-0f23a3fa-ada4-4dd9-ae09-332904cc0a85.png#averageHue=%23dddbdb&clientId=ue5880cbc-94bc-4&from=paste&height=257&id=u490806be&originHeight=386&originWidth=969&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=75664&status=done&style=none&taskId=u6c54795d-6963-44b6-8175-c69b621e38c&title=&width=646)

按照规则，二叉树的遍历有：**前序/中序/后序**的递归结构遍历：

1. 前序遍历(Preorder Traversal亦称先序遍历)一一访问根结点的操作发生在遍历其左右子树之前。
2. 中序遍历(Inorder Traversal))一一访问根结点的操作发生在遍历其左右子树之中（间）。
3. 后序遍历(Postorder Traversal))一一访问根结点的操作发生在遍历其左右子树之后。

由于被访问的结点必是某子树的根，所以N(Node)、L(Left subtree)和R(Right subtree)又可解释为根、根的左子树和根的右子树。NLR、LNR和LRN分别又称为先根遍历、中根遍历和后根遍历。

**前序遍历**递归图解：

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709868046120-e791c11a-cfc5-4d9a-b62f-350da6aab555.png#averageHue=%23e0f6dc&clientId=ue5880cbc-94bc-4&from=paste&height=431&id=u4c69e5b9&originHeight=647&originWidth=1342&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=714124&status=done&style=none&taskId=u6b7c5599-796f-46d5-be42-9d1288b875a&title=&width=894.6666666666666)

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709868100399-f03f940f-57fb-451c-a26b-6f234c9227b9.png#averageHue=%23fbfafa&clientId=ue5880cbc-94bc-4&from=paste&height=647&id=ubff27a38&originHeight=971&originWidth=1391&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=654244&status=done&style=none&taskId=ub97060da-e4b3-47a8-bf8b-4bf6ec51f0e&title=&width=927.3333333333334)

前序遍历结果：123456

中序遍历结果：321546

后序遍历结果：325641

（2）层序遍历

层序遍历：除了先序遍历、中序遍历、后序遍历外，还可以对二叉树进行层序遍历。设二叉树的根节点所在层数为1，层序遍历就是从所在二叉树的根节点出发，首先访问第一层的树根节点，然后从左到右访问第2层上的节点，接着是第三层的节点，以此类推，自上而下，自左至右逐层访问树的结点的过程就是层序遍历。

![image.png](https://cdn.nlark.com/yuque/0/2024/png/29309193/1709868210726-3c8b04c4-97fd-475f-9f48-9e248b0828f4.png#averageHue=%23fafafa&clientId=ue5880cbc-94bc-4&from=paste&height=258&id=u730d0b69&originHeight=387&originWidth=983&originalType=binary&ratio=1.5&rotation=0&showTitle=false&size=91510&status=done&style=none&taskId=ueacb24dd-6d39-43a0-bf4a-fc70be08cda&title=&width=655.3333333333334)

```c
//二叉树前序遍历
void PreOrder(BTNode* root);
//二叉树中序遍历
void InOrder(BTNode* root);
//二叉树后序遍历
void PostOrder(BTNode* root);
//层序遍历
void LevelOrder(BTNode* root);

//二叉树节点个数
int BinaryTreeSize(BTNode* root);
//二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
//二叉树第k层节点个数
int BinaryTreeLevelkSize(BTNode* root,int k);
//二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root,BTDataType x);

//二叉树的创建和销毁
//通过前序遍历的数组"ABD##EH##CF##G#"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a,int n,int* pi);
//二叉树销毁
void BinaryTreeDestory(BTNode** root);
//判断二又树是否是完全二又树
int BinaryTreeComplete(BTNode* root);
```

