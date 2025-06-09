              SongshengMemory - Malloc ทรงเช็ง

🧠 Concept:
------------------------------------------------------------
"Malloc ทรงเช็ง" (SongshengMemory) คือระบบจัดการหน่วยความจำ 
ที่รวม malloc() หลายครั้งไว้ในลิงก์ลิสต์กลางเดียว 
เพื่อให้สามารถเรียก free() ทีเดียวได้อย่างปลอดภัย

แรงบันดาลใจจากความเป็นระเบียบของ "ทรงเช็ง" 
ที่เน้นความสะอาดและความเป็นระบบในชีวิตประจำวัน

🛠 Purpose:
------------------------------------------------------------
- รวมทุก malloc ที่เกิดจาก shloc() ไว้ในโครงสร้างลิงก์ลิสต์เดียว
- สามารถ cleanup ทั้งหมดได้ในครั้งเดียวผ่าน shfree()
- เหมาะกับโปรเจกต์ที่มี memory allocation หลายจุด 
  และต้องการความสะอาดตอนจบโปรแกรมหรือ scope

📦 Components:
------------------------------------------------------------
1. shloc(size_t size)
   - ทำหน้าที่เหมือน malloc() แต่จะเก็บ pointer ไว้ในระบบ
   - คืนค่า pointer ที่ใช้ได้ตามปกติ

2. shfree(void)
   - ลูปลิงก์ลิสต์เพื่อ free() ทั้งตัวข้อมูลและ node
   - ใช้ทีเดียวล้างทุก allocation ที่เคยใช้ shloc()

3. create_shnode(void *ptr)
   - สร้าง node เพื่อเก็บ pointer ที่ malloc ได้
   - ใช้ภายในเท่านั้น

4. get_list(void)
   - คืนค่า pointer ไปยัง static list
   - ทำงานแบบ singleton ไม่สามารถสร้างหลายชุดได้

📋 Norminette Compatibility (42 Norm):
------------------------------------------------------------
- ไม่มี global variable
- ไม่มี static function
- ไม่มี inline initialization
- function declaration และ definition แยกบรรทัด
- ไม่เกิน 25 บรรทัดต่อฟังก์ชัน
- ไม่มี {} เปิดในบรรทัดเดียวกับชื่อฟังก์ชัน
- มีช่องว่างระหว่าง declarations และ logic code

🚫 ข้อควรระวัง:
------------------------------------------------------------
- ห้ามใช้ shloc() แล้วลืม shfree()
- อย่า free() pointer ที่ได้จาก shloc() ด้วยตัวเอง
- ไม่มี thread safety (ใช้ได้ใน single-thread เท่านั้น)

🧪 Example Usage:
------------------------------------------------------------
```c
#include "shmem.h"

void	*data1;
void	*data2;

data1 = shloc(sizeof(int) * 10);
data2 = shloc(sizeof(char) * 50);

// ใช้งาน data1 และ data2 ได้ตามปกติ

shfree(); // ล้างทุก allocation ที่เคยขอผ่าน shloc()
