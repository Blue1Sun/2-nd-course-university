using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DoorKeyAndArms
{
    class Program
    {
        static bool DoorIsOpen; //1 задание
        static bool UserHaveArms; //1 задание
        static bool UserHaveKey; //1 задание
        static string UserName;
        static int NumberThatUserSaid;

        static void Main(string[] args)
        {
            SystemText("ДИСКЛЕЙМЕР".PadLeft(44));
            SystemText("ПРЕДУПРЕЖДЕНИЕ".PadLeft(46));
            SystemText("Автор данного шЫдевра не несет отстветственности за то, что сейчас будет происходить.");
            SystemText("                   Нажмите что угодно, чтобы продолжить...");
            Console.ReadKey();
            Console.Clear();

            History();

            SystemText("\r\n                   Нажмите что угодно, чтобы выйти из игры...");
            Console.ReadKey();
        }

        static void History()
        {
            SystemText("Ты просыпаешься с жуткой головной болью, словно весь вчерашний день тебе\r\nпросверливали висок снова и снова.");
        
            UserText("\"Божечки, да что же вчера было?..\"");
            
            SystemText(" - спрашиваешь ты себя, приоткрывая глаза.\r\nЛучше бы ты этого не делал.");
            
            OldManText("- Здравствуй, заблудший путник...");
           
            SystemText(" - прямо над тобой нависает морщинистое лицо старца.");
            
            UserText("- ЧТО ЗА %&&%##% ?!");

            SystemText(" - ты подрываешься с пола.");
            
            OldManText("- Не стоит кричать, лучше назови мне свое имя...\r\n");
            
            UserText("- Эммм... Ну, меня зовут ");
            UserName = Console.ReadLine();

            OldManText("- Отлично, " + UserName + ", скажи мне, открыта ли эта дверь?..");

            SystemText(" - старец указывает на дверь.\r\nПохоже он думает, что ты Ванга.");
            SystemText("                   Введите да/нет");
            CheckAnswer("door");

            OldManText("- Отлично... А теперь скажи мне, есть ли у тебя руки?.. Что? Я слепой и не вижу этого.");

            SystemText("                   Введите да/нет");
            CheckAnswer("arms");

            OldManText("- Просто замечательно... А теперь загляни в свой карман, есть ли там ключ?..");

            SystemText("                   Введите да/нет");
            CheckAnswer("key");

            SystemText("                   Нажмите что угодно, чтобы продвинуться дальше...");
            Console.ReadKey();
            Console.Clear();

            SystemText("                      " + UserName + " information:");

            SystemText("     ████████████████████████████████████████████████████████");
            SystemText("     █  Дверь открыта █ У тебя есть руки █ У тебя есть ключ █");
            SystemText("     ████████████████████████████████████████████████████████");
            SystemText("     █      " + DoorIsOpen.ToString().PadRight(10) + "█      " + UserHaveArms.ToString().PadRight(12) + "█      " + UserHaveKey.ToString().PadRight(12) + "█");
            SystemText("     ████████████████████████████████████████████████████████");
            
            if (DoorIsOpen||(UserHaveKey&&UserHaveArms)) //2 задание
            {
                OldManText("- Поздравляю, ты можешь пройти через эту дверь!..\r\n");
                UserText("\"Он точно сбрендил...\"\r\n");
            }
            else //2 задание
            {
                OldManText("- Что ж, тогда мы с тобой останемся тут навечно... Бугагашеньки\r\n");
                Ending("GAME OVER. BAD ENDING");
                return;
            }

            SystemText("Ты выходишь на улицу. Тебя на мгновение ослепляет свет, но очень скоро ты к нему привыкаешь.\r\nПеред тобой лес, позади уже исчезли дверь и загадочный старец.");

            RepeatingBird();

            SystemText("                   Нажмите что угодно, чтобы продвинуться дальше...");
            Console.ReadKey();
            Console.Clear();

            SystemText("Ты продолжаешь идти вперед, как вдруг перед тобой вырастает ОГРОМНАЯ стена.\r\nПрямо по ее центру находится нечто, напоминающее домофон.");

            BirdText("- Скажите число!");

            SystemText(" - кажется, или это голос той птицы?..");

            BirdText("- Вы сказали число " + EnterNumber());

            SystemText("\r\nТы счастливо выдыхаешь - стена открывает перед тобой проход,\r\nпрямо как в Гарри Поттере. Но тут ты понимаешь - создатель этой недоигры\r\nеще недостаточно постебался над тобой.");
            SystemText("Скалясь от злобы ты видишь перед собой еще один \"домофон\"");

            BirdText("- Скажите число!");

            SystemText(" - вновь вещает отвратительный голос птицы.");
            SystemText("Однако на этот раз ты с ужасом осознаешь, что можешь произносить только числа!");

            OnlyNumbers();

            SystemText("\r\nТы ошеломленно моргаешь глазами, в то время как стена снова распадается.");
            SystemText("Теперь перед тобой стоит стол, а на нем компьютер.Голос в твоей голове шепчет - садись и играй");
            SystemText("На дисплей наклеен стикер, на котором написано\"Нажми Enter и этот кошмар закончится...\"");

            SystemText("                   Нажмите что угодно, чтобы начать игру...");
            SystemText("                 Передвижение осуществляется кнопками WASD...");
            Console.ReadKey();
            Console.Clear();
            
            BestGameInTheWorld();

            UserText("- Ну и игра!");

            SystemText(" - восклицаешь ты.");
            SystemText("Неожиданно стол и компьютер исчезают, а ты оказываешься в чистом поле.\r\nСВОБОДА?!");
            SystemText("Ты начинаешь безудержно смеяться от радости. Весь этот бред закончился и можно отдохнуть!");

            OldManText("- Не так быстро...");

            SystemText(" - слышится сзади голос, который ты ни с чьим не спутаешь.\r\nГолос старика.");

            OldManText("- Ты знаешь слишком много");

            SystemText(" - эта фраза - последнее, что ты слышишь в своей жизни\r\nперед тем как подлый старик убивает тебя кинжалом в спину...");
            
            Ending("GAME OVER. BAD ENDING");

            SystemText("            Чтобы получить хорошую концовку приобретите DLC за 99$");
        }


        static void OldManText(string Text)
        {
            Console.ForegroundColor = ConsoleColor.DarkMagenta;
            Console.Write(Text);
        }

        static void SystemText(string Text)
        {
            Console.ResetColor();
            Console.WriteLine(Text);
        }

        static void UserText(string Text)
        {
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.Write(Text);
        }

        static void Ending(string Text)
        {
            Console.WriteLine("");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine(Text.PadLeft(50));
        }

        static void BirdText(string Text)
        {
            Console.ForegroundColor = ConsoleColor.DarkGreen;
            Console.Write(Text);
        }


        static void CheckAnswer(string mode)
        {
            string UserAnswer;

            do
            {
                UserText("- ");
                UserAnswer = Console.ReadLine();

                if (UserAnswer.ToLower() != "нет" && UserAnswer.ToLower() != "да")
                {
                    OldManText("- Ты в бреду, странник?.. Выпей воды и попробуй еще раз...\r\n");
                }
            }
            while (UserAnswer.ToLower() != "нет" && UserAnswer.ToLower() != "да");

            if (mode == "door")
            {
                if (UserAnswer.ToLower() == "нет")
                {
                    DoorIsOpen = false;
                }
                else
                {
                    DoorIsOpen = true;
                }
            }

            else if (mode == "arms")
            {
                if (UserAnswer.ToLower() == "нет")
                {
                    UserHaveArms = false;
                }
                else
                {
                    UserHaveArms = true;
                }
            }

            else
            {
                if (UserAnswer.ToLower() == "нет")
                {
                    UserHaveKey = false;
                }
                else
                {
                    UserHaveKey = true;
                }
            }
        }

        static void RepeatingBird() //3 задание, 4 задание
        {
            int amount;
            string UserCommand;

            BirdText("- Скажите \"Кыш\", чтобы прогнать меня или \"Го\", чтобы начать повторение");

            SystemText(" - ты поднимаешь голову и видишь здоровенного попугая. Он явно ждет твоей команды");

            do
            {
                UserText("- ");
                UserCommand = Console.ReadLine();

                if (UserCommand.ToLower() == "го")
                {
                    BirdText("- ЗАПИСЬ ВАШЕГО ГОЛОСА ПОШЛА!\r\n");

                    UserText("- ");
                    string UserTalk = Console.ReadLine();

                    BirdText("- ЗАПИСЬ ЗАКОНЧЕНА. Сколько раз повторить сообщение? Лимит повторов равен 20.\r\n");

                    do
                    {
                        UserText("- ");
                        amount = Convert.ToInt32(Console.ReadLine());

                        if (amount > 20)
                        {
                            BirdText("- Превышен лимит повторов, повторите число!\r\n");
                        }
                    } while (amount > 20);

                    BirdText("- ");

                    for (int i = 0; i < amount; i++)
                    {
                        BirdText(UserTalk + " ");
                    }

                    BirdText("\r\n- \"Кыш\" или \"Го\"?\r\n");
                }
                if (UserCommand.ToLower() != "кыш" && UserCommand.ToLower() != "го")
                {
                    BirdText("- Неизвестная мне команда! Повторите!\r\n");
                }
            } while (UserCommand.ToLower() != "кыш");

            SystemText("\r\nПопугай довольно замахал крыльями и улетел.");
        }

        static int EnterNumber() //5 задание
        {
            bool FlagForNumber = false;

            do
            {
                try
                {
                    UserText("- ");
                    NumberThatUserSaid = Convert.ToInt32(Console.ReadLine());
                    FlagForNumber = true;
                }
                catch
                {
                    BirdText("- Я требую число!\r\n");
                }
            } while (!FlagForNumber);

            return NumberThatUserSaid;
        }

        static void OnlyNumbers() //6 задание
        {
            ConsoleKeyInfo UserKey;

            UserText("- ");

            do
            {
                UserKey = Console.ReadKey(true);

                if (UserKey.Key == ConsoleKey.D0 || 
                    UserKey.Key == ConsoleKey.D1 || 
                    UserKey.Key == ConsoleKey.D2 || 
                    UserKey.Key == ConsoleKey.D3 || 
                    UserKey.Key == ConsoleKey.D4 || 
                    UserKey.Key == ConsoleKey.D5 || 
                    UserKey.Key == ConsoleKey.D6 || 
                    UserKey.Key == ConsoleKey.D7 || 
                    UserKey.Key == ConsoleKey.D8 || 
                    UserKey.Key == ConsoleKey.D9)
                {
                    Console.Write(UserKey.KeyChar);
                }
            } while (UserKey.Key != ConsoleKey.Enter);

        }

        static void BestGameInTheWorld() //7 задание
        {            
            int x = 15;
            int y = 15;
            ConsoleKeyInfo PressedButton;

            Console.CursorVisible = false; 

            do
            {
                Console.SetCursorPosition(x, y);
                Console.Write("&");
                PressedButton = Console.ReadKey(true);

                if (PressedButton.Key == ConsoleKey.W && y > 0)
                {
                    y--;
                }
                else if (PressedButton.Key == ConsoleKey.S && y < 79)
                {
                    y++;
                }
                else if (PressedButton.Key == ConsoleKey.A && x > 0)
                {
                    x--;
                }
                else if (PressedButton.Key == ConsoleKey.D && x < 79)
                {
                    x++;
                }
                Console.Clear();
            } while (PressedButton.Key != ConsoleKey.Enter); 

        }
    }
}
