# include "minitalk.h"

static void	ft_handler(int signal)
{
	static int	bit; // 비트를 얼마나 받았는 지 확인하는 정적 변수
	static char	tmp; // 문자값을 저장하는 정적 변수

	if (signal == SIGUSR1) // SIGUSR2 일 때는 어차피 0이므로 pass 가능
		tmp |= (1 << bit); // 가장 오른쪽 비트부터 추가해줌
	bit++;
	if (bit == 8) // 비트가 8이 될 경우 저장된 문자를 출력하고 정적변수 초기화
	{
		ft_putchar_fd(tmp, 1);
		bit = 0;
		tmp = 0;
	}
}

static void	ft_pid_print(pid_t pid) // pid 출력
{
	ft_putstr_fd("PID -> ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Waiting for a message...\n", 1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1) // 인자가 1개일 경우 예외처리
	{
		ft_putstr_fd("Error: worng format.\n", 1);
		ft_putstr_fd("Try: ./server\n", 1);
		return (0);
	}
	pid = getpid(); // pid를 받아오기
	ft_pid_print(pid); // pid 출력
    // SIGUSR1신호와 SIGUSR2 신호 입력시 ft_handler함수 호출
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (argc == 1)
		pause(); // 신호가 입력될 때 까지 대기
	return (0);
}