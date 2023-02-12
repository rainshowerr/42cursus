# include "minitalk.h"

static void	ft_send_bit(pid_t pid, char input)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
    	// 가장 오른쪽 비트부터 왼쪽으로 가면서 전송함
        // 1을 bit만큼 left shift 연산 한 값을 input과 &연산
		if ((input & (1 << bit)) != 0)
		{
			printf("1");
			kill(pid, SIGUSR1); // 해당 값이 1일 경우 SIGUSR1 신호 전송
		}
		else
		{
			printf("0");
			kill(pid, SIGUSR2); // 해당 값이 0일 경우 SIGUSR2 신호 전송
		}
		usleep(100); // 딜레이를 위해
		bit++;
	}
}

static void	ft_send_str(pid_t pid, char input[])
{
	int	i;

	i = 0;
	while (input[i] != '\0') // 한 문자씩 전송함
	{
		ft_send_bit(pid, input[i]);
		i++;
	}
	ft_send_bit(pid, '\n');
	ft_send_bit(pid, '\0'); // 문자열 전송을 끝냈다는 것을 알리기 위한 널문자 전송
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3 && argv[2][0] != '\0') // 인자가 정확할 경우
	{
		pid = ft_atoi(argv[1]); // 입력한 pid 받아오기
		if (pid < 100 || pid > 99999) // pid의 범위처리 100 ~ 99999
		{
			ft_putstr_fd("Error: wrong pid.\n", 1);
			return (0);
		}
		ft_send_str(pid, argv[2]); // 문자열을 한 번에 전달
	}
	else // 인자가 유효하지 않은 경우
	{
		ft_putstr_fd("Error: wrong format.\n", 1);
		ft_putstr_fd("Try: ./client [PID] [MESSAGE]\n", 1);
	}
	return (0);
}