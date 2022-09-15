#include <mlx.h>

int main(){
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "winter");
	mlx_loop(mlx);
	return (0);
}