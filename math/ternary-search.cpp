// pustit jako tern(1, 1e9) apod
ld tern(ld l, ld r)
{
  if (r - l < 1e-6) 
    return func((l + r) / 2);
  ld lt = (2 * l + r) / 3;
  ld rt = (l + 2 * r) / 3;

  // flipnout na < pro maximum
  if (func(lt) > func(rt))
    return tern(lt, r);
  else
    return tern(l, rt);
}
