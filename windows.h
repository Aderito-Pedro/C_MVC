#include <windows.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int windows(const char pasta[],const char nome[]);

/**
*
*	Prototipos para a pasta app...
*
**/
void app(const char pasta[],const char nome[]);
void config(const char pasta[],const char nome[]);
void controller(const char pasta[]);
void help(const char pasta[]);
void livraria(const char pasta[]);
void model(const char pasta[]);
void views(const char pasta[]);
void include(const char pasta[]);
void paginas(const char pasta[]);

/**
*
*	Prototipos para a pasta public
*
**/
void publics(const char pasta[],const char nome[]);
void css(const char pasta[]);
void img(const char pasta[]);
void js1(const char pasta[]);

/**
*
*	Prototipos para os metodos que criam os ficheiros (.HTACCESS)
*
**/
void publicFcH(const char pasta[],const char nome[]);
void publicFc(const char pasta[],const char nome[]);
void appFcH(const char pasta[]);
void appFcH1(const char pasta[]);
void projectFcH(const char pasta[]);

/**
*
*	Prototipos para os metodos que criam os ficheiros nas pastas do (APP)
*
**/
void configFcH(const char pasta[],const char nome[]);
void controllerFcH(const char pasta[]);
void livrariaFcH_B(const char pasta[]);
void livrariaFcH_C(const char pasta[]);
void livrariaFcH_Core(const char pasta[]);
void includeFcH_H(const char pasta[]);
void includeFcH_F(const char pasta[]);
void paginasFCH(const char pasta[]);

/**
*
*	Prototipos para os metodos que criam os ficheiros nas pastas do (PUBLIC)
*
**/
void indexFCH(const char pasta[]);
void cssFCH(const char pasta[]);
void jsFCH(const char pasta[]);

//Metodo responsavel por criar todo o Projecto
int windows(const char pasta[],const char nome[]){
	struct stat st = {0};
	if (stat(pasta, &st) == -1) {
		if(mkdir(pasta) == 0){
			projectFcH(pasta);
			fflush(stdin);
			publics(pasta,nome);
			fflush(stdin);
			app(pasta,nome);
			fflush(stdin);
			configFcH(pasta,nome);
			fflush(stdin);
			controllerFcH(pasta);
			fflush(stdin);
			livrariaFcH_C(pasta);
			livrariaFcH_Core(pasta);
			livrariaFcH_B(pasta);
			includeFcH_H(pasta);
			includeFcH_F(pasta);
			paginasFCH(pasta);
			indexFCH(pasta);
			publicFc(pasta,nome);
			cssFCH(pasta);
			jsFCH(pasta);
			return 1;
		}
	}
	return 0;
}

//Metodo responsavel por cria toda pasta app
void app(const char pasta[],const char nome[]){
	static char app[] = {""};
	strcpy(app,pasta);
	strcat(app,"\\app");
	mkdir(app);
	config(pasta,nome);
	fflush(stdin);
	controller(pasta);
	help(pasta);
	livraria(pasta);
	model(pasta);
	views(pasta);
	fflush(stdin);
	appFcH(pasta);
	fflush(stdin);
	appFcH1(pasta);
}

//Metodo responsavel por criar toda a pasta public
void publics(const char pasta[],const char nome[]){
	static char publics[] = {""};
	strcpy(publics,pasta);
	strcat(publics,"\\public");
	mkdir(publics);
	js1(pasta);
	css(pasta);
	img(pasta);
	fflush(stdin);
}

//Metodo responsavel por criar a pasta css na pasta \public
void css(const char pasta[]) {
	static char css [] = {""};
  	strcpy(css,pasta);
	strcat(css,"\\public\\css");
	mkdir(css);
}

//Metodo responsavel por criar a pasta img na pasta \public
void img(const char pasta[]) {
	static char img [] = {""};
  	strcpy(img,pasta);
	strcat(img,"\\public\\img");
	mkdir(img);
}

//Metodo responsavel por criar a pasta js na pasta \public
void js1(const char pasta[]) {
	static char js [] = {""};
  	strcpy(js,pasta);
	strcat(js,"\\public\\js");
	mkdir(js);
}

//Metodo responsavel por criar a pasta config na pasta \app
void config(const char pasta[],const char nome[]){
	static char config [] = {""};
  	strcpy(config,pasta);
	strcat(config,"\\app\\config");
	mkdir(config);
	fflush(stdin);
}

//Metodo responsavel por criar a pasta controller na pasta \app
void controller(const char pasta[]){
	static char controller [] = {""};
  	strcpy(controller,pasta);
	strcat(controller,"\\app\\controller");
	mkdir(controller);
}

//Metodo responsavel por criar a pasta help na pasta \app
void help(const char pasta[]){
	static char help [] = {""};
  	strcpy(help,pasta);
	strcat(help,"\\app\\help");
	mkdir(help);
}

//Metodo responsavel por criar a pasta livraria na pasta \app
void livraria(const char pasta[]){
	static char livraria [] = {""};
  	strcpy(livraria,pasta);
	strcat(livraria,"\\app\\livraria");
	mkdir(livraria);
}

//Metodo responsavel por criar a pasta model na pasta \app
void model(const char pasta[]){
	static char model [] = {""};
  	strcpy(model,pasta);
	strcat(model,"\\app\\model");
	mkdir(model);
}

//Metodo responsavel por criar a pasta views na pasta \app
void views(const char pasta[]){
	static char views [] = {""};
  	strcpy(views,pasta);
	strcat(views,"\\app\\views");
	mkdir(views);
	include(pasta);
	paginas(pasta);
}

//Metodo responsavel por criar a pasta include na pasta \app\views
void include(const char pasta[]){
	static char include [] = {""};
  	strcpy(include,pasta);
	strcat(include,"\\app\\views\\include");
	mkdir(include);
}

//Metodo responsavel por criar a pasta paginas na pasta \app\views
void paginas(const char pasta[]){
	static char paginas [] = {""};
  	strcpy(paginas,pasta);
	strcat(paginas,"\\app\\views\\paginas");
	mkdir(paginas);
}

//Metodo responsavel por criar o ficheiro HTACCESS na pasta principal do projecto
void projectFcH(const char pasta[]){
	FILE *htaccess;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\.htaccess");
	htaccess = fopen (caminho,"w");
	static char string[]={"<IfModule mod_rewrite.c>\nRewriteEngine on\nRewriteRule ^$ public/ [L]\nRewriteRule (.*) public/$1 [L]\n</IfModule>\n"};
	int i,tm;
	tm=strlen(string);
	for(i=0; string[i]; i++) putc(string[i],htaccess);
	fclose (htaccess);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro HTACCESS na pasta \app
void appFcH(const char pasta[]){
	FILE *htaccess;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\app\\.htaccess");
	htaccess = fopen (caminho,"w");
	static char string[]={"Options -Indexes"};
	int i,tm;
	tm=strlen(string);
	for(i=0; string[i]; i++) putc(string[i],htaccess);
	fclose (htaccess);
	fflush(stdin);

}

//Matodo responsavel por criar o ficheiro INICIALIZADOR na pasta \app
void appFcH1(const char pasta[]){
	FILE *inicializador;
	static char caminho1[] = {""};
	strcat(caminho1,pasta);
	strcat(caminho1,"\\app\\inicializador.php");
	inicializador = fopen (caminho1,"w");
	static char code[]={"<?php\n\n\t//Carregamento das livrarias\n\trequire_once 'config/Configuracao.php';\n\n\t//Autoload php\n\tspl_autoload_register(function($nomeClass){\n\t\trequire_once 'livraria/'.$nomeClass.'.php';\n\t});\n\n"};
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++) putc(code[j],inicializador);
	fclose (inicializador);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro CONFIGURAÇÃO na pasta \app\config
void configFcH(const char pasta[],const char nome[]){
	FILE *configuracao;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\app\\config\\Configuracao.php");
	configuracao = fopen (caminho,"w");
	static char code[]={"<?php\n\n\t// Configuração da base de dados\n\tdefine('BD_HOST','localhost');\n\tdefine('BD_USER','_TEU_USER_');\n\tdefine('BD_PASSWORD','_TUA_PASSWORD_');\n\tdefine('BD_NOME','_TUA_BASE_DE_DADOS_');\n\n\t//Rotas da aplicação\n\tdefine('ROTA_APP', dirname(dirname(__FILE__)));\n\t//Rota da url Ex:http://localhost/"};
	strcat(code,nome);
	strcat(code,"/\n\tdefine('ROTA_URL','http://localhost/");
	strcat(code,nome);
	strcat(code,"/');\n\n\tdefine('NOME_LOCAL','");
	strcat(code,nome);
	strcat(code,"');\n\n");
	fflush(stdin);
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++){
		putc(code[j],configuracao);
		fflush(stdin);
	}
	fclose (configuracao);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro PAGINAS na pasta \app\controller
void controllerFcH(const char pasta[]){
	FILE *paginas;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\app\\controller\\Paginas.php");
	paginas = fopen (caminho,"w");
	static char code[]={"<?php\n\n\tclass Paginas extends Controlador{\n\n\t\tpublic function __construct(){\n\n\t\t}\n\n\t\tpublic function index(){\n\t\t\t$dados = ['titulo' => 'Bem Vindo'];\n\t\t\t$this->views ('paginas/inicio',$dados);\n\t\t}\n\n\n}\n"};
	fflush(stdin);
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++){
		putc(code[j],paginas);
		fflush(stdin);
	}
	fclose (paginas);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro CONTROLADOR na pasta \app\livraria
void livrariaFcH_C(const char pasta[]){
	FILE *controlador;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\app\\livraria\\Controlador.php");
	controlador = fopen (caminho,"w");
	static char code[]={"<?php\n\t//Controlador Principal\n\t//Que vai se encaregar de carregar as model e as views\n\tclass Controlador{\n\t\t//Carregar modeln\n\t\tpublic function model($model){\n\t\t\trequire_once '../app/model/'.$model.'.php';\n\t\t\treturn new $model;\n\t\t}\n\n\t\t//Carregar views\n\t\tpublic function views($views,$dados = []){\n\t\t\tif (file_exists('../app/views/'.$views.'.php')) {\n\t\t\t\trequire_once '../app/views/'.$views.'.php';\n\t\t\t}else {\n\t\t\t\t//Se o ficheiro da views não existir\n\t\t\t\tdie('A Views não Existe');\n\t\t\t}\n\t\t}\n\t}"};
	fflush(stdin);
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++){
		putc(code[j],controlador);
		fflush(stdin);
	}
	fclose (controlador);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro CORE na pasta \app\livraria
void livrariaFcH_Core(const char pasta[]){
	FILE *core;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\app\\livraria\\Core.php");
	core = fopen (caminho,"w");
	static char code[]={"<?php\n\t/**\n\t* mapeamento da url\n\t* 1 - Controlador\n\t* 2 - Metodos\n\t* 3 - Parametros\n\t* por Ex: /conrolador/metodo/parameto\n\t*/\n\n\tclass Core {\n\t\tprotected $controladorAtual = 'paginas';\n\t\tprotected $metodoAtual = 'index';\n\t\tprotected $parametros = [];\n\n\t\tpublic function __construct(){\n\t\t\t$url = $this->getUrl();\n\t\t\t//Buscar Controlador se ele existir\n\t\t\tif(file_exists('../app/controller/'.ucwords($url[0]).'.php')){\n\t\t\t\t//Se existir o controlador\n\t\t\t\t$this->controladorAtual = ucwords($url[0]);\n\t\t\t\tunset($url[0]);\n\t\t\t}\n\t\t\trequire_once ('../app/controller/'.$this->controladorAtual.'.php');\n\t\t\t$this->controladorAtual = new $this->controladorAtual;\n\t\t\t//Segunda parte da url (metodo)\n\t\t\tif (isset($url[1])) {\n\t\t\t\tif (method_exists($this->controladorAtual, $url[1])) {\n\t\t\t\t\t$this->metodoAtual = $url[1];\n\t\t\t\t\t\tunset($url[1]);\n\t\t\t\t}\n\t\t\t}\n\t\t\t//Terceira parte da url (parametros)\n\t\t\t$this->parametros = $url ? array_values($url) : [];\n\t\t\tcall_user_func_array([$this->controladorAtual, $this->metodoAtual], $this->parametros);\n\t\t}\n\n\t\t//Metodo que retorna a URL\n\t\tpublic function getUrl(){\n\t\t\tif(isset($_GET['url'])){\n\t\t\t\t$url = rtrim($_GET['url'],'/');\n\t\t\t\t$url = filter_var($url,FILTER_SANITIZE_URL);\n\t\t\t\t$url = explode('/',$url);\n\t\t\t\treturn $url;\n\t\t\t}\n\t\t}\n\n\t}"};
	fflush(stdin);
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++){
		putc(code[j],core);
		fflush(stdin);
	}
	fclose (core);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro BASE na pasta \app\livraria
void livrariaFcH_B(const char pasta[]){
	FILE *base;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\app\\livraria\\Base.php");
	base = fopen (caminho,"w");
	static char code[]={"<?php\n\t//Class para a Conexão com a base de dados\n\t//Conexão PDO\n\tclass Base{\n\t\tprivate $host = BD_HOST;\n\t\tprivate $user = BD_USER;\n\t\tprivate $password = BD_PASSWORD;\n\t\tprivate $bd_nome = BD_NOME;\n\n\t\tprivate $dbh;\n\t\tprivate $stmt;\n\t\tprivate $erro;\n\n\t\tpublic function __construct(){\n\t\t\t//configuração da conexão\n\t\t\t$dsn = 'mysql:host='.$this->host.';dbname='.$this->bd_nome;\n\t\t\t$opciones = array(\n\t\t\t\tPDO::ATTR_PERSISTENT => true,\n\t\t\t\tPDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION\n\t\t\t);\n\n\t\t\t//Criação da instancia de PDO\n\t\t\ttry {\n\t\t\t\t$this->dbh = new PDO($dsn,$this->user,$this->password,$opciones);\n\t\t\t\t$this->dbh->exec('set names utf8');\n\t\t\t} catch (PDOException $e) {\n\t\t\t\t$this->erro = $e->getMessage();\n\t\t\t\techo $this->erro;\n\t\t\t}\n\t\t}\n\t//\n\t\tpublic function query($sql){\n\t\t\t$this->stmt = $this->dbh->prepare($sql);\n\t\t}\n\n\t\tpublic function bind($parametro,$valor,$tipo = null){\n\t\t\tif (is_null($tipo)) {\n\t\t\t\tswitch (true) {\n\t\t\t\t\tcase is_int($valor):\n\t\t\t\t\t\t$tipo = PDO::PARAM_INT;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\tcase is_bool($valor):\n\t\t\t\t\t\t$tipo = PDO::PARAM_BOOL;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\tcase is_null($valor):\n\t\t\t\t\t\t$tipo = PDO::PARAM_NULL;\n\t\t\t\t\t\tbreak;\n\t\t\t\t\tdefault:\n\t\t\t\t\t\t$tipo = POD::PARAM_STR;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\t$this->stmt->bindValue($parametro, $valor, $tipo);\n\t\t}\n\t\t//Metodo Executar\n\t\tpublic function execute(){\n\t\t\treturn $this->stmt->execute();\n\t\t}\n\t\t//Obter todos registo\n\t\tpublic function registos(){\n\t\t\t$this->execute();\n\t\t\treturn $this->stmt->fetchAll(PDO::FETCH_OBJ);\n\t\t}\n\n\t\tpublic function registo(){\n\t\t\t$this->execute();\n\t\t\treturn $this->stmt->fetch(PDO::FETCH_OBJ);\n\t\t}\n\n\t\tpublic function rowCount(){\n\t\t\treturn $this->stmt->rowCount;\n\t\t}"};
	fflush(stdin);
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++){
		putc(code[j],base);
		fflush(stdin);
	}
	fclose (base);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro HEADER na pasta \app\views\include
void includeFcH_H(const char pasta[]){
	FILE *header;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\app\\views\\include\\header.php");
	header = fopen (caminho,"w");
	static char code[]={"<!DOCTYPE html>\n<html lang=\"pt\">\n\t<head>\n\t\t<meta charset=\"UTF-8\">\n\t\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n\t\t<meta http-equiv=\"X-UA-Compatible\" content=\"id=edge\">\n\t\t<link rel=\"stylesheet\" type=\"text/css\" href=\"<?php echo ROTA_URL;?>/css/estilo.css\">\n\t\t<title><?php echo NOME_LOCAL; ?></title>\n\t</head>\n\t<body>\n"};
	fflush(stdin);
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++){
		putc(code[j],header);
		fflush(stdin);
	}
	fclose (header);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro FOOTER na pasta \app\views\include
void includeFcH_F(const char pasta[]){
	FILE *footer;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\app\\views\\include\\footer.php");
	footer = fopen (caminho,"w");
	static char code[]={"\n\t\t<script type=\"text/javascript\" src=\"<?php echo ROTA_URL;?>/js/main.js\"></script>\n\t</body>\n\t</html>\n"};
	fflush(stdin);
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++){
		putc(code[j],footer);
		fflush(stdin);
	}
	fclose (footer);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro INICIO na pasta \app\views\paginas
void paginasFCH(const char pasta[]){
	FILE *inicio;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\app\\views\\paginas\\inicio.php");
	inicio = fopen (caminho,"w");
	static char code[]={"<?php require ROTA_APP.'/views/include/header.php';?>\n<h3><?php echo $dados['titulo']; ?></h3>\n<p>AO TEU PROJECTO USANDO PADRÃO \"MVC\"</p>\n<?php require ROTA_APP.'/views/include/footer.php';?>\n"};
	fflush(stdin);
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++){
		putc(code[j],inicio);
		fflush(stdin);
	}
	fclose (inicio);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro INDEX na pasta \public
void indexFCH(const char pasta[]){
	FILE *index;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\public\\index.php");
	index = fopen (caminho,"w");
	static char code[]={"<?php\n\n\trequire_once '../app/inicializador.php';\n\n\t/** INSTACIA DA CLASS CONTROLADOR */\n\n\t$iniciar = new Core;\n"};
	fflush(stdin);
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++){
		putc(code[j],index);
		fflush(stdin);
	}
	fclose (index);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro HTACCESS na pasta \public
void publicFc(const char pasta[],const char nome[]){
	FILE *index;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\public\\.htaccess");
	index = fopen (caminho,"w");
	static char code[]={"<IfModule mod_rewrite.c>\nOptions -Multiviews\nRewriteEngine On\nRewriteBase /"};
	strcat(code,nome);
	strcat(code,"/public\nRewriteCond %{REQUEST_FILENAME} !-d\nRewriteCond %{REQUEST_FILENAME} !-f\nRewriteRule ^(.+)$ index.php?url=$1 [QSA,L]\n</IfModule>\n");
	fflush(stdin);
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++){
		putc(code[j],index);
		fflush(stdin);
	}
	fclose (index);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro ESTILO na pasta \public\css
void cssFCH(const char pasta[]){
	FILE *estilo;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\public\\css\\estilo.css");
	estilo = fopen (caminho,"w");
	static char code[]={"  "};
	fflush(stdin);
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++){
		putc(code[j],estilo);
		fflush(stdin);
	}
	fclose (estilo);
	fflush(stdin);
}

//Matodo responsavel por criar o ficheiro MAIN na pasta \public\js
void jsFCH(const char pasta[]){
	FILE *mainjs;
	static char caminho[] = {""};
	strcat(caminho,pasta);
	strcat(caminho,"\\public\\js\\main.js");
	mainjs = fopen (caminho,"w");
	static char code[]={" "};
	fflush(stdin);
	int j,tn;
	tn=strlen(code);
	for(j=0; code[j]; j++){
		putc(code[j],mainjs);
		fflush(stdin);
	}
	fclose (mainjs);
	fflush(stdin);
}