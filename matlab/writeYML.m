function writeYML( opts )
%
%	writeYML( opts)
%
%	Create a YML file that represents an opencv matrix.
%
%	Arguments:	opts Matlab sructure
%
%				opts fields:
%				----------------------------------
%				opts.fpath = fully qualified or relative path name of newly created YML file
%				opts.mtx = is a Matlab matrix
%				opts.prec = floating point precision (optional, default is 3)
%
% 	Example:
%				opts.mtx = rand(10,9);
%				opts.fpath = '/home/user/test.yml';
%				writeYML( opts );
%
%	Notes:
%				Only writes floating point matrices
%				Default precision is 3 decimal places.
%

DEBUG = false;

[m,n]=size( opts.mtx );

precision = '%.3f';

if isfield( opts, 'prec' ),
	precision = ['%.' num2str(opts.prec) 'f'];

end;

X=reshape(opts.mtx',m*n,1);

if DEBUG, fprintf([precision '\n'], X(1) ); end;

fid = fopen( opts.fpath, 'w' );

fprintf(fid, '%%YAML:1.0\n');
fprintf(fid, 'mtx: !!opencv-matrix\n');
fprintf(fid, '   rows: %d\n', m );
fprintf(fid, '   cols: %d\n', n );
fprintf(fid, '   dt: f\n');
fprintf(fid, '   data: [');

for i=1:length(X)-1, 
    
    fprintf( fid, [' ' precision ','], X(i) );
    
end;

fprintf( fid, [' ' precision ' ]\n' ], X(end) );

fclose( fid );