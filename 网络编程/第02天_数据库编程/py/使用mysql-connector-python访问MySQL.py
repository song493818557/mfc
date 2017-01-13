#0.导入模块
import mysql.connector

def main():
    #--------------------------------------------------------------------------------
    #1.连接数据库
    #--------------------------------------------------------------------------------
    config={'host':'127.0.0.1',           #默认127.0.0.1
            'user':'root',
            'password':'888888',
            'port':3307 ,                   #默认即为3306
            'database':'game_info',
            'charset':'utf8'               #默认即为utf8
            }

    #conn = mysql.connector.connect(user='root', password='gqmyyh', database='test')
    conn = mysql.connector.connect(**config)

    #--------------------------------------------------------------------------------
    #2.SQL操作
    #--------------------------------------------------------------------------------
    try:
        cursor = conn.cursor()
        # 创建表:
        cursor.execute('DROP TABLE IF EXISTS test;')
        cursor.execute('CREATE TABLE test(id int primary key, name varchar(20))')
        # 插入记录，注意MySQL的占位符是%s:
        cursor.execute('INSERT INTO test(id, name) VALUES (%s, %s)', (1, '哇哈哈'))
        print('rowcount =', cursor.rowcount)
        # 提交事务:
        conn.commit()
        cursor.close()

        # 查询:
        cursor = conn.cursor()
        cursor.execute('SELECT * FROM test WHERE id = %s', ('1',))
        values = cursor.fetchall()
        print(values)

    except:
        # 发生错误时回滚
        conn.rollback()

    #--------------------------------------------------------------------------------
    #3.关闭连接
    #--------------------------------------------------------------------------------

    cursor.close()
    conn.close()

if __name__ == "__main__":
    main()